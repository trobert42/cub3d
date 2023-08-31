/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:15 by trobert           #+#    #+#             */
/*   Updated: 2022/12/07 15:37:38 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	free_split(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_parsing(t_data *data)
{
	if (data->path_n_texture)
		free(data->path_n_texture);
	if (data->path_e_texture)
		free(data->path_e_texture);
	if (data->path_s_texture)
		free(data->path_s_texture);
	if (data->path_w_texture)
		free(data->path_w_texture);
	if (data->floor_rgb_str)
		free(data->floor_rgb_str);
	if (data->ceiling_rgb_str)
		free(data->ceiling_rgb_str);
	if (data->tab_map)
		free_split(data->tab_map);
}

void	free_img_mlx(t_mlx *mlx)
{
	if (mlx->e_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->e_wall.xpm);
	if (mlx->w_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->w_wall.xpm);
	if (mlx->n_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->n_wall.xpm);
	if (mlx->s_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->s_wall.xpm);
	if (mlx->new_img.xpm)
		mlx_destroy_image(mlx->mlx, mlx->new_img.xpm);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
}

void	free_all(t_data *data)
{
	free_parsing(data);
	free_img_mlx(&data->mlx);
	if (data->ray)
		free(data->ray);
	free((&data->mlx)->mlx);
	exit(0);
}
