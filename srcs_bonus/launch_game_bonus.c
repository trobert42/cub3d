/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 18:26:44 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	init_raycast_var(t_data *d, t_ray *ray)
{
	d->half_screen = W_H / 2;
	ray->plane_x = 0.66f;
	ray->plane_y = 0;
	ray->time = 0;
	ray->old_time = 0;
}

t_list	*init_door_var(t_data *data, t_list *lst_door, int x, int y)
{
	t_list	*new;

	new = ft_lstnew(NULL);
	new->id = data->door_nbr - 1;
	if (new->id == 0)
		data->lst_door = new;
	new->is_open = false;
	new->x = x;
	new->y = y;
	ft_lstadd_back(&lst_door, new);
	return (lst_door);
}

void	init_and_count_door(t_data *data, t_list *lst_door)
{
	int	x;
	int	y;

	y = 0;
	lst_door = NULL;
	data->door_nbr = 0;
	while (y < data->h)
	{
		x = 0;
		while (x < data->w)
		{
			if (data->tab_map[y][x] == 'D')
			{
				data->door_nbr++;
				lst_door = init_door_var(data, lst_door, x, y);
			}
			x++;
		}
		y++;
	}
}

void	game_loop(t_data *d, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < W_W)
	{
		d->first_collision_x = -1;
		d->first_collision_y = -1;
		init_raycast_var_loop(d, ray, x);
		get_step_xy(d, ray);
		get_wall_dist(d, ray);
		get_wall_height(d, ray);
		draw_lines(d, ray, x);
		x++;
	}
	mouse_move(d);
	if (W_H >= 500 && W_W >= 500)
		minimap(d);
	anim_loop(d);
	if (d->i_anim == 48)
		d->i_anim = 0;
	d->i_anim++;
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.mlx_win,
		d->mlx.new_img.xpm, 0, 0);
}

void	launch_game(t_data *data)
{
	data->tab_map[(int)data->player_y][(int)data->player_x] = '0';
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_exit(data, "malloc for stuct has failed\n");
	init_and_count_door(data, data->lst_door);
	init_raycast_var(data, data->ray);
	init_player_var(data);
	game_loop(data, data->ray);
}
