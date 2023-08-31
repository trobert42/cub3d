/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 09:41:27 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_raycast_var_loop(t_data *d, t_ray *ray, int x)
{
	ray->camera_x = 2 * x / (double) W_W - 1;
	ray->ray_dir_x = d->player_dir_x + ray->plane_x * ray->camera_x;
	ray->ray_dir_y = d->player_dir_y + ray->plane_y * ray->camera_x;
	ray->map_x = (int)d->player_x;
	ray->map_y = (int)d->player_y;
	ray->delta_dist_x = 1e30;
	if (ray->ray_dir_x != 0)
		ray->delta_dist_x = fabs(1 / ray->ray_dir_x);
	ray->delta_dist_y = 1e30;
	if (ray->ray_dir_y != 0)
		ray->delta_dist_y = fabs(1 / ray->ray_dir_y);
	ray->hit = 0;
}

void	get_step_xy(t_data *d, t_ray *ray)
{
	if (ray->ray_dir_x < 0)
	{
		ray->step_x = -1;
		ray->side_dist_x = (d->player_x - ray->map_x) * ray->delta_dist_x;
	}
	else
	{
		ray->step_x = 1;
		ray->side_dist_x = (ray->map_x + 1.0 - d->player_x) * ray->delta_dist_x;
	}
	if (ray->ray_dir_y < 0)
	{
		ray->step_y = -1;
		ray->side_dist_y = (d->player_y - ray->map_y) * ray->delta_dist_y;
	}
	else
	{
		ray->step_y = 1;
		ray->side_dist_y = (ray->map_y + 1 - d->player_y) * ray->delta_dist_y;
	}
}

void	get_wall_dist(t_data *d, t_ray *ray)
{
	while (ray->hit == 0)
	{
		if (ray->side_dist_x < ray->side_dist_y)
		{
			ray->side_dist_x += ray->delta_dist_x;
			ray->map_x += ray->step_x;
			if (ray->map_x >= d->player_x)
				ray->side = 0;
			else
				ray->side = 1;
		}
		else
		{
			ray->side_dist_y += ray->delta_dist_y;
			ray->map_y += ray->step_y;
			if (ray->map_y > d->player_y)
				ray->side = 2;
			else
				ray->side = 3;
		}
		if (ray->map_x >= d->w && ray->map_y >= d->h)
			ray->hit = 1;
		else if (d->tab_map[ray->map_y][ray->map_x] == '1')
			ray->hit = 1;
	}
}

void	get_wall_height(t_data *d, t_ray *ray)
{
	if (ray->side == 0 || ray->side == 1)
		ray->wall_dist = (ray->side_dist_x - ray->delta_dist_x);
	else
		ray->wall_dist = (ray->side_dist_y - ray->delta_dist_y);
	if (ray->wall_dist < 0.005)
		ray->wall_h = W_H;
	else
	ray->wall_h = (int)(W_H / (ray->wall_dist));
	ray->cut_ceil_wall = d->half_screen - ray->wall_h / 2;
	if (ray->cut_ceil_wall < 0)
		ray->cut_ceil_wall = 0;
	ray->cut_wall_floor = ray->wall_h + ray->cut_ceil_wall;
	if (ray->cut_wall_floor >= W_H)
		ray->cut_wall_floor = W_H - 1;
}

void	game_loop(t_data *d, t_ray *ray)
{
	int	x;

	x = 0;
	while (x < W_W)
	{
		init_raycast_var_loop(d, ray, x);
		get_step_xy(d, ray);
		get_wall_dist(d, ray);
		get_wall_height(d, ray);
		draw_lines(d, ray, x);
		x++;
	}
	mlx_put_image_to_window(d->mlx.mlx, d->mlx.mlx_win,
		d->mlx.new_img.xpm, 0, 0);
}
