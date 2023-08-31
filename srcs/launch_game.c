/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launch_game.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 09:45:20 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_raycast_var(t_data *d, t_ray *ray)
{
	d->half_screen = W_H / 2;
	d->player_dir_x = 0;
	d->player_dir_y = -1;
	ray->plane_x = 0.66f;
	ray->plane_y = 0;
	ray->time = 0;
	ray->old_time = 0;
}

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

void	launch_game(t_data *data)
{
	data->tab_map[(int)data->player_y][(int)data->player_x] = '0';
	data->ray = malloc(sizeof(t_ray));
	if (!data->ray)
		error_exit(data, "malloc for stuct has failed\n");
	init_raycast_var(data, data->ray);
	init_player_orientation(data, data->ray);
	data->player_x += 0.5;
	data->player_y += 0.5;
	game_loop(data, data->ray);
}
