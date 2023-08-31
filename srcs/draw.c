/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 09:39:25 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	put_pixel_into_img(t_data *data, int x, int y, int color)
{
	char		*pixel;
	t_img_data	*img;

	img = &data->mlx.new_img;
	if (x < 0 || x >= W_W || y < 0 || y >= W_H)
		return ;
	pixel = img->addr + (y * img->size_line + x * (img->bpp / 8));
	*(unsigned int *)pixel = color;
}

void	draw_one_line(t_mlx *mlx, int x1, float y2, int color)
{
	float	y1;

	y1 = mlx->dataa->ray->cut_wall_floor;
	while (y1 != y2)
	{
		put_pixel_into_img(mlx->dataa, x1, y1, color);
		y1++;
	}
}

void	draw_ceil_line(t_mlx *mlx, int x1, float y2, int color)
{
	float	y1;

	y1 = 0;
	while (y1 != y2)
	{
		put_pixel_into_img(mlx->dataa, x1, y1, color);
		y1++;
	}
}

void	draw_wall(t_data *data, t_ray *ray, t_img_data wall, int x)
{
	if (ray->side == 0 || ray->side == 1)
		ray->wall_x = data->player_y + ray->wall_dist * ray->ray_dir_y;
	else
		ray->wall_x = data->player_x + ray->wall_dist * ray->ray_dir_x;
	ray->wall_x -= floor(ray->wall_x);
	ray->tex_x = (int)(ray->wall_x * (double)data->mlx.img_w);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		ray->tex_x = data->mlx.img_w - ray->tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		ray->tex_x = data->mlx.img_w - ray->tex_x - 1;
	get_pixel_texture(data, ray, wall, x);
}

void	draw_lines(t_data *data, t_ray *ray, int x)
{
	t_img_data	wall;

	if (ray->side == 0)
		wall = data->mlx.e_wall;
	else if (ray->side == 1)
		wall = data->mlx.w_wall;
	else if (ray->side == 2)
		wall = data->mlx.s_wall;
	else
		wall = data->mlx.n_wall;
	draw_ceil_line(&data->mlx, x, ray->cut_ceil_wall, data->ceiling_rgb);
	draw_wall(data, ray, wall, x);
	draw_one_line(&data->mlx, x, W_H, data->floor_rgb);
}
