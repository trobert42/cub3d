/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:23:41 by trobert           #+#    #+#             */
/*   Updated: 2022/12/13 14:09:23 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	init_var(t_data *data)
{
	data->fd = -1;
	data->h = 0;
	data->w = 0;
	data->flag = 0;
	data->path_n_texture = NULL;
	data->path_e_texture = NULL;
	data->path_s_texture = NULL;
	data->path_w_texture = NULL;
	data->floor_rgb_str = NULL;
	data->ceiling_rgb_str = NULL;
	data->tab_map = NULL;
	data->ray = NULL;
	(&data->mlx)->mlx = NULL;
	(&data->mlx)->mlx_win = NULL;
	(&data->mlx)->new_img.xpm = NULL;
	(&data->mlx)->n_wall.xpm = NULL;
	(&data->mlx)->e_wall.xpm = NULL;
	(&data->mlx)->s_wall.xpm = NULL;
	(&data->mlx)->w_wall.xpm = NULL;
	(&data->mlx)->new_img.addr = NULL;
	(&data->mlx)->n_wall.addr = NULL;
	(&data->mlx)->s_wall.addr = NULL;
	(&data->mlx)->e_wall.addr = NULL;
	(&data->mlx)->w_wall.addr = NULL;
}
