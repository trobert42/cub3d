/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:59 by trobert           #+#    #+#             */
/*   Updated: 2022/12/13 12:25:29 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	print_raycast_info(t_data *d)
{
	printf("player_dir_x = %f \n", d->player_dir_x);
	printf("player_dir_y = %f \n", d->player_dir_y);
	printf("plane_x = %f \n", d->ray->plane_x);
	printf("plane_y = %f \n", d->ray->plane_y);
	printf("camera_x = %f \n", d->ray->camera_x);
	printf("ray_dir_x = %f \n", d->ray->ray_dir_x);
	printf("ray_dir_y = %f \n", d->ray->ray_dir_y);
	printf("map_x = %d \n", d->ray->map_x);
	printf("map_y = %d \n", d->ray->map_y);
	printf("delta_dist_x = %f \n", d->ray->delta_dist_x);
	printf("delta_dist_y = %f \n", d->ray->delta_dist_y);
	printf("side_dist_x = %f \n", d->ray->side_dist_x);
	printf("side_dist_y = %f \n", d->ray->side_dist_y);
	printf("wall_dist = %f \n", d->ray->wall_dist);
	printf("wall_h = %d \n", d->ray->wall_h);
}

void	display_map(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (data->tab_map && data->tab_map[i])
	{
		j = 0;
		while (data->tab_map[i][j])
		{
			if (data->tab_map[i][j] == '\n')
				printf("[n]");
			else
				printf("[%c]", data->tab_map[i][j]);
			j++;
		}
		printf("\n");
		i++;
	}
}

void	display_config(t_data *data)
{
	printf("path n texture = [%s]\n", data->path_n_texture);
	printf("path e texture = [%s]\n", data->path_e_texture);
	printf("path s texture = [%s]\n", data->path_s_texture);
	printf("path w texture = [%s]\n\n", data->path_w_texture);
	printf("floor_rgb_str = [%s]\n", data->floor_rgb_str);
	printf("ceiling_rgb_str = [%s]\n\n", data->ceiling_rgb_str);
	printf("data->width = [%d]\n", data->w);
	printf("data->height = [%d]\n\n", data->h);
	printf("data->floor_rgb = [%d]\n", data->floor_rgb);
	printf("data->ceiling_rgb = [%d]\n", data->ceiling_rgb);
}
