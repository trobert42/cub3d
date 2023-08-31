/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_var_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:23:41 by trobert           #+#    #+#             */
/*   Updated: 2022/12/13 18:14:20 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

static void	init_xpm_null(t_data *data)
{
	(&data->mlx)->new_img.xpm = NULL;
	(&data->mlx)->n_wall.xpm = NULL;
	(&data->mlx)->e_wall.xpm = NULL;
	(&data->mlx)->s_wall.xpm = NULL;
	(&data->mlx)->w_wall.xpm = NULL;
	(&data->mlx)->d_wall.xpm = NULL;
	(&data->anim)->anim1.xpm = NULL;
	(&data->anim)->anim2.xpm = NULL;
	(&data->anim)->anim3.xpm = NULL;
	(&data->anim)->anim4.xpm = NULL;
	(&data->anim)->anim5.xpm = NULL;
	(&data->anim)->anim6.xpm = NULL;
	(&data->anim)->anim7.xpm = NULL;
	(&data->anim)->anim8.xpm = NULL;
	(&data->anim)->anim9.xpm = NULL;
	(&data->anim)->anim10.xpm = NULL;
	(&data->anim)->anim11.xpm = NULL;
	(&data->anim)->anim12.xpm = NULL;
}

static void	init_addr_null(t_data *data)
{
	(&data->mlx)->new_img.addr = NULL;
	(&data->mlx)->n_wall.addr = NULL;
	(&data->mlx)->s_wall.addr = NULL;
	(&data->mlx)->e_wall.addr = NULL;
	(&data->mlx)->w_wall.addr = NULL;
	(&data->mlx)->d_wall.addr = NULL;
	(&data->anim)->anim1.addr = NULL;
	(&data->anim)->anim2.addr = NULL;
	(&data->anim)->anim3.addr = NULL;
	(&data->anim)->anim4.addr = NULL;
	(&data->anim)->anim5.addr = NULL;
	(&data->anim)->anim6.addr = NULL;
	(&data->anim)->anim7.addr = NULL;
	(&data->anim)->anim8.addr = NULL;
	(&data->anim)->anim9.addr = NULL;
	(&data->anim)->anim10.addr = NULL;
	(&data->anim)->anim11.addr = NULL;
	(&data->anim)->anim12.addr = NULL;
}

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
	init_addr_null(data);
	init_xpm_null(data);
	data->i_anim = 0;
	data->door_open = false;
	data->lst_door = NULL;
	data->minimap_start_x = W_W - (5 * SCALE) - (W_W * 0.05);
	data->minimap_start_y = (W_H) * 0.05;
}
