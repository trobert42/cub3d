/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_cam_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:17:14 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 10:14:12 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	move_cam_right(t_data *d)
{
	double	old_dx;
	double	old_dy;
	double	old_plane_x;
	double	old_plane_y;

	old_dx = d->player_dir_x;
	old_dy = d->player_dir_y;
	old_plane_x = d->ray->plane_x;
	old_plane_y = d->ray->plane_y;
	d->player_dir_x = old_dx * cos(0.1) - old_dy * sin(0.1);
	d->player_dir_y = old_dx * sin(0.1) + old_dy * cos(0.1);
	d->ray->plane_x = old_plane_x * cos(0.1) - old_plane_y * sin(0.1);
	d->ray->plane_y = old_plane_x * sin(0.1) + old_plane_y * cos(0.1);
}

void	move_cam_left(t_data *d)
{
	double	old_dx;
	double	old_dy;
	double	old_plane_x;
	double	old_plane_y;

	old_dx = d->player_dir_x;
	old_dy = d->player_dir_y;
	old_plane_x = d->ray->plane_x;
	old_plane_y = d->ray->plane_y;
	d->player_dir_x = old_dx * cos(-0.1) - old_dy * sin(-0.1);
	d->player_dir_y = old_dx * sin(-0.1) + old_dy * cos(-0.1);
	d->ray->plane_x = old_plane_x * cos(-0.1) - old_plane_y * sin(-0.1);
	d->ray->plane_y = old_plane_x * sin(-0.1) + old_plane_y * cos(-0.1);
}

void	mouse_move(t_data *d)
{
	int	x;
	int	y;

	mlx_mouse_get_pos(d->mlx.mlx, d->mlx.mlx_win, &x, &y);
	(void)y;
	if (x > W_W / 2)
		move_cam_right(d);
	else if (x < W_W / 2)
		move_cam_left(d);
	mlx_mouse_move(d->mlx.mlx, d->mlx.mlx_win, (int)W_W / 2, (int)W_H / 2);
}
