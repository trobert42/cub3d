/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 14:59:53 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	init_player_orientation(t_data *d, t_ray *ray)
{
	double	old_dir_x;
	double	old_dir_y;
	double	old_plane_x;
	double	old_plane_y;

	if (d->player_orientation == 'N')
		return ;
	else if (d->player_orientation == 'S')
		d->player_angle = PI;
	else if (d->player_orientation == 'W')
		d->player_angle = (PI / 2) * -1;
	else if (d->player_orientation == 'E')
		d->player_angle = PI / 2;
	old_dir_x = d->player_dir_x;
	old_dir_y = d->player_dir_y;
	old_plane_x = ray->plane_x;
	old_plane_y = ray->plane_y;
	d->player_dir_x = old_dir_x * cos(d->player_angle) - old_dir_y
		* sin(d->player_angle);
	d->player_dir_y = old_dir_x * sin(d->player_angle) + old_dir_y
		* cos(d->player_angle);
	ray->plane_x = old_plane_x * cos(d->player_angle) - old_plane_y
		* sin(d->player_angle);
	ray->plane_y = old_plane_x * sin(d->player_angle) + old_plane_y
		* cos(d->player_angle);
}

void	init_player_var(t_data *data)
{
	data->player_dir_x = 0;
	data->player_dir_y = -1;
	data->player_x += 0.5;
	data->player_y += 0.5;
	init_player_orientation(data, data->ray);
}

void	check_img_size_anim(t_data *data)
{
	t_anim	a;
	int		sum;
	int		tot;

	a = data->anim;
	sum = data->anim.anim1.h * 12;
	tot = a.anim1.h + a.anim2.h + a.anim3.h + a.anim4.h + a.anim5.h + a.anim6.h
		+ a.anim7.h + a.anim8.h + a.anim9.h + a.anim10.h + a.anim11.h
		+ a.anim12.h;
	if (sum != tot)
		error_exit(data, "Animation textures' height are not the same\n");
	sum = data->anim.anim1.w * 12;
	tot = a.anim1.w + a.anim2.w + a.anim3.w + a.anim4.w + a.anim5.w + a.anim6.w
		+ a.anim7.w + a.anim8.w + a.anim9.w + a.anim10.w + a.anim11.w
		+ a.anim12.w;
	if (sum != tot)
		error_exit(data, "Animation textures' width are not the same\n");
}
