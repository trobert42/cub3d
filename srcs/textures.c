/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by trobert           #+#    #+#             */
/*   Updated: 2022/12/12 09:46:18 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	get_color_texture(t_mlx *mlx, t_img_data wall, int tex_x, int tex_y)
{
	int	i;
	int	j;
	int	color;

	i = (mlx->img_h - tex_x) * 4;
	j = 0;
	while (j < tex_y)
	{
		i += wall.size_line;
		j++;
	}
	color = (wall.addr[i + 2] * 256 * 256) + (wall.addr[i + 1] * 256)
		+ wall.addr[i];
	return (color);
}

void	get_pixel_texture(t_data *data, t_ray *ray, t_img_data wall, int x)
{
	int	y;
	int	color;

	y = ray->cut_ceil_wall;
	ray->step = 1.0 * data->mlx.img_h / ray->wall_h;
	ray->tex_pos = (ray->cut_ceil_wall - W_H / 2 + ray->wall_h / 2) * ray->step;
	while (y < ray->cut_wall_floor)
	{
		ray->tex_y = (int)ray->tex_pos;
		ray->tex_pos += ray->step;
		color = get_color_texture(&data->mlx, wall, ray->tex_x, ray->tex_y);
		put_pixel_into_img(data, x, y, color);
		y++;
	}
}
