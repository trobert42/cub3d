/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_mlx_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/13 10:59:44 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 11:03:14 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	free_img_anim(t_data *data, t_mlx *mlx)
{
	if (data->anim.anim1.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim1.xpm);
	if (data->anim.anim2.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim2.xpm);
	if (data->anim.anim3.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim3.xpm);
	if (data->anim.anim4.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim4.xpm);
	if (data->anim.anim5.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim5.xpm);
	if (data->anim.anim6.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim6.xpm);
	if (data->anim.anim7.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim7.xpm);
	if (data->anim.anim8.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim8.xpm);
	if (data->anim.anim9.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim9.xpm);
	if (data->anim.anim10.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim10.xpm);
	if (data->anim.anim11.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim11.xpm);
	if (data->anim.anim12.xpm)
		mlx_destroy_image(mlx->mlx, data->anim.anim12.xpm);
}

void	free_img_mlx(t_data *data, t_mlx *mlx)
{
	if (mlx->e_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->e_wall.xpm);
	if (mlx->w_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->w_wall.xpm);
	if (mlx->n_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->n_wall.xpm);
	if (mlx->s_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->s_wall.xpm);
	if (mlx->d_wall.xpm)
		mlx_destroy_image(mlx->mlx, mlx->d_wall.xpm);
	if (mlx->new_img.xpm)
		mlx_destroy_image(mlx->mlx, mlx->new_img.xpm);
	free_img_anim(data, mlx);
	if (mlx->mlx_win)
		mlx_destroy_window(mlx->mlx, mlx->mlx_win);
	if (mlx->mlx)
		mlx_destroy_display(mlx->mlx);
}
