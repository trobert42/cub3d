/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 16:55:15 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 10:57:43 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

static void	check_condition_draw_square(t_data *d, double y, double x)
{
	t_list	*door;
	double	j;
	double	i;

	j = (d->player_y * SCALE) + y;
	i = (d->player_x * SCALE) + x;
	if ((i / SCALE) <= 0 || (j / SCALE) >= d->h)
		return ;
	if (d->tab_map[(int)floor(j / SCALE)][(int)floor(i / SCALE)] == '0')
		put_pixel_into_img(d, d->begin_x, d->begin_y, SNOW);
	else if (d->tab_map[(int)floor(j / SCALE)][(int)floor(i / SCALE)] == '1')
		put_pixel_into_img(d, d->begin_x, d->begin_y, ONYX);
	else if (d->tab_map[(int)floor(j / SCALE)][(int)floor(i / SCALE)] == 'D')
	{
		door = which_door(d->lst_door, (int)floor(i / SCALE),
				(int)floor(j / SCALE));
		if (door->is_open == false)
			put_pixel_into_img(d, d->begin_x, d->begin_y, YELLOW);
		else
			put_pixel_into_img(d, d->begin_x, d->begin_y, LIGHT_YELLOW);
	}
}

void	draw_mini_square(t_data *d)
{
	int	x;
	int	y;

	y = 0;
	while (y <= 6)
	{
		x = 0;
		while (x <= 6)
		{
			put_pixel_into_img(d, (d->minimap_start_x + d->begin_x) / 2 + x,
				(d->minimap_start_y + d->begin_y) / 2 + y, RED);
			x++;
		}
		y++;
	}
}

void	draw_direction(t_data *data)
{
	int		z;
	double	pos_point_x;
	double	pos_point_y;

	z = 0;
	pos_point_x = (data->minimap_start_x + data->begin_x) / 2 + 3;
	pos_point_y = (data->minimap_start_y + data->begin_y) / 2 + 3;
	while (z < 18)
	{
		put_pixel_into_img(data, pos_point_x, pos_point_y, RED);
		pos_point_x += data->player_dir_x;
		pos_point_y += data->player_dir_y;
		z++;
	}
}

int	minimap(t_data *d)
{
	double	x;
	double	y;

	d->begin_y = d->minimap_start_y;
	y = -2.5 * SCALE;
	while (y < 2.5 * SCALE)
	{
		x = -2.5 * SCALE;
		d->begin_x = d->minimap_start_x;
		while (x < 2.5 * SCALE)
		{
			if ((d->player_y + y / SCALE < 0) || \
				(d->player_y + y / SCALE > d->h))
				d->begin_x = d->begin_x;
			else
				check_condition_draw_square(d, y, x);
			d->begin_x++;
			x += 1;
		}
		d->begin_y++;
		y += 1;
	}
	return (draw_mini_square(d), draw_direction(d), 0);
}
