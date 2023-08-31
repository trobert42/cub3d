/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 16:39:27 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 18:21:49 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	close_window(t_mlx *mlx)
{
	printf("Byebye!\n");
	return (free_all(mlx->dataa), 0);
}

static int	key_catch(int keycode, t_data *data)
{
	if (keycode == ESC_KEY)
		return (close_window(&data->mlx));
	else if (keycode == W_KEY)
		data->mlx.w_key = true;
	else if (keycode == A_KEY)
		data->mlx.a_key = true;
	else if (keycode == S_KEY)
		data->mlx.s_key = true;
	else if (keycode == D_KEY)
		data->mlx.d_key = true;
	else if (keycode == LEFT_ARROW)
		data->mlx.left_key = true;
	else if (keycode == RIGHT_ARROW)
		data->mlx.right_key = true;
	else if (keycode == E_KEY)
		check_open(data, data->ray);
	return (0);
}

static int	key_catch_release(int keycode, t_mlx *mlx)
{
	if (keycode == W_KEY)
		mlx->w_key = false;
	else if (keycode == A_KEY)
		mlx->a_key = false;
	else if (keycode == S_KEY)
		mlx->s_key = false;
	else if (keycode == D_KEY)
		mlx->d_key = false;
	else if (keycode == LEFT_ARROW)
		mlx->left_key = false;
	else if (keycode == RIGHT_ARROW)
		mlx->right_key = false;
	return (0);
}

int	check_key_status(t_data *data)
{
	if (data->mlx.w_key == true)
		ft_move_front(data);
	if (data->mlx.a_key == true)
		ft_move_left(data);
	if (data->mlx.s_key == true)
		ft_move_back(data);
	if (data->mlx.d_key == true)
		ft_move_right(data);
	if (data->mlx.left_key == true)
		move_cam_left(data);
	if (data->mlx.right_key == true)
		move_cam_right(data);
	game_loop(data, data->ray);
	return (0);
}

void	ft_hook(t_data *data)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	mlx_loop_hook(mlx->mlx, check_key_status, data);
	mlx_hook(mlx->mlx_win, 2, 1L << 0, key_catch, data);
	mlx_hook(mlx->mlx_win, 3, 1L << 1, key_catch_release, mlx);
	mlx_hook(mlx->mlx_win, 33, 1L << 17, close_window, mlx);
}
