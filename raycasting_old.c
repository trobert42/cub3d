/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting_old.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/11/29 19:12:24 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

float	rad(int deg_angle)
{
	return (deg_angle * 3.14159265358979323846264338327950288 / 180);
}
		
void	draw_one_line(t_data *d, t_mlx *mlx, int x1, float y1, int x2, float y2, int color)
{
	(void) x1;
	(void) x2;
	while (y1 != y2)
	{
		mlx_pixel_put(mlx->mlx, mlx->mlx_win, d->ray_count, y1, color);
		y1++;		
	}	
}

void	raycasting(t_data *d, t_mlx *mlx)
{
	char	wall;

	while (d->ray_count < d->screen_w)
	{
		// fixing the ray at the position of the player
		d->ray_x = d->player_x; 
		d->ray_y = d->player_y;

		// calculus of the cos and sinus with the angle information
		d->ray_cos = cos(rad(d->ray_angle)) / d->precision;
		d->ray_sin = sin(rad(d->ray_angle)) / d->precision;

		//incrementing the ray to find where it hits the walln
		wall = '0';
		while (wall != '1')
		{
			printf("x = [%f], y = [%f]\n", d->ray_x, d->ray_y);
			d->ray_x += d->ray_cos;
			d->ray_y += d->ray_sin;
			printf("x = [%f], y = [%f]\n", d->ray_x, d->ray_y);
			// checking the coordination of the ray with the map info
			wall = d->tab_map[(int)floor(d->ray_y)][(int)floor(d->ray_x)];
		}
		// pythagore formula to find the distance between the wall and the player
		float test = pow(d->player_x - (int)floor(d->ray_x), 2) + pow(d->player_y - (int)floor(d->ray_y), 2);
		d->wall_dist = sqrt(test);
		d->wall_dist = d->wall_dist * cos(rad(d->ray_angle - d->player_angle));
		
		d->wall_h = floor(d->half_screen / d->wall_dist);
		if(d->wall_h > d->half_screen)
			d->wall_h = d->half_screen;
		
		// drawing the ceiling, wall, and the floor
		draw_one_line(d, mlx, d->ray_count, 0, d->ray_count, d->half_screen - d->wall_h, 20); // ceiling
		draw_one_line(d, mlx, d->ray_count, d->half_screen - d->wall_h, d->ray_count, d->half_screen + d->wall_h, 120); // wall
		draw_one_line(d, mlx, d->ray_count, d->half_screen + d->wall_h, d->ray_count, d->screen_h, 255); // floor
	
		// passing to the second drawing vertical line 
		d->ray_count++;
		d->ray_angle += d->increment_angle;
	}
}

void	init_raycasting(t_data *d, t_mlx *mlx)
{
	(void)mlx;
	d->screen_w = 1000;
	d->screen_h = 700;
	d->ray_count = 0;
	d->half_screen = d->screen_h / 2;
	d->fov = 60;
	d->player_angle = 0;
	d->ray_angle = d->player_angle - (d->fov / 2); // [60° ; 120°]
	d->increment_angle = d->fov / d->screen_w;
	d->precision = 64;
}

/*
N = 270
W = 180
S = 90
E = 360 or 0	
*/