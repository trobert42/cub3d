/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:42:27 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/13 10:48:17 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	calcul_move(t_data *d, int flag)
{
	if (flag == 0)
	{
		d->player_x += d->player_dir_x * SPEED;
		d->player_y += d->player_dir_y * SPEED;
	}
	else if (flag == 1)
	{
		d->player_x -= d->player_dir_x * SPEED;
		d->player_y -= d->player_dir_y * SPEED;
	}
	else if (flag == 2)
	{
		d->player_x += d->player_dir_y * SPEED;
		d->player_y -= d->player_dir_x * SPEED;
	}
	else if (flag == 3)
	{
		d->player_x -= d->player_dir_y * SPEED;
		d->player_y += d->player_dir_x * SPEED;
	}
}

void	ft_move_front(t_data *d)
{
	t_list	*door;

	door = which_door(d->lst_door, (int)(d->player_x + d->player_dir_x * 0.3),
			(int)(d->player_y + d->player_dir_y * 0.3));
	if (d->tab_map[(int)d->player_y][(int)d->player_x] == 'D'
		&& d->tab_map[(int)(d->player_y + d->player_dir_y * 0.3)]
		[(int)d->player_x] != '1' && d->tab_map[(int)d->player_y][(int)
		(d->player_x + d->player_dir_x * 0.3)] != '1')
		calcul_move(d, 0);
	else if (d->tab_map[(int)(d->player_y + d->player_dir_y * 0.3)]
		[(int)d->player_x] == '0' && d->tab_map[(int)d->player_y][(int)
		(d->player_x + d->player_dir_x * 0.3)] == '0')
		calcul_move(d, 0);
	else if (d->lst_door && door->is_open == true)
	{
		if (d->tab_map[(int)(d->player_y + d->player_dir_y * 0.3)]
			[(int)d->player_x] != '1' && d->tab_map[(int)d->player_y]
			[(int)(d->player_x + d->player_dir_x * 0.3)] != '1')
			calcul_move(d, 0);
	}
}

void	ft_move_back(t_data *d)
{
	t_list	*door;

	door = which_door(d->lst_door, (int)(d->player_x - d->player_dir_x * 0.3),
			(int)(d->player_y - d->player_dir_y * 0.3));
	if (d->tab_map[(int)d->player_y][(int)d->player_x] == 'D'
		&& d->tab_map[(int)(d->player_y - d->player_dir_y * 0.3)]
		[(int)d->player_x] != '1' && d->tab_map[(int)d->player_y][(int)
		(d->player_x - d->player_dir_x * 0.3)] != '1')
		calcul_move(d, 1);
	else if (d->tab_map[(int)(d->player_y - d->player_dir_y * 0.3)]
		[(int)d->player_x] == '0' && d->tab_map[(int)d->player_y][(int)
		(d->player_x - d->player_dir_x * 0.3)] == '0')
		calcul_move(d, 1);
	else if (d->lst_door && door->is_open == true)
	{
		if (d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_x
			* 0.3)] != '1' && d->tab_map[(int)(d->player_y - d->player_dir_y
			* 0.3)][(int)d->player_x] != '1')
			calcul_move(d, 1);
	}
}

void	ft_move_left(t_data *d)
{
	t_list	*door;

	door = which_door(d->lst_door, (int)(d->player_x + d->player_dir_y * 0.3),
			(int)(d->player_y - d->player_dir_x * 0.3));
	if (d->tab_map[(int)d->player_y][(int)d->player_x] == 'D'
		&& d->tab_map[(int)d->player_y][(int)(d->player_x + d->player_dir_y
		* 0.3)] != '1' && d->tab_map[(int)(d->player_y - d->player_dir_x * 0.3)]
		[(int)d->player_x] != '1')
		calcul_move(d, 2);
	else if (d->tab_map[(int)d->player_y][(int)(d->player_x + d->player_dir_y
		* 0.3)] == '0' && d->tab_map[(int)(d->player_y - d->player_dir_x * 0.3)]
		[(int)d->player_x] == '0')
		calcul_move(d, 2);
	else if (d->lst_door && door->is_open == true)
	{
		if (d->tab_map[(int)d->player_y][(int)(d->player_x + d->player_dir_y
			* 0.3)] != '1' && d->tab_map[(int)(d->player_y - d->player_dir_x
			* 0.3)][(int)d->player_x] != '1')
			calcul_move(d, 2);
	}
}

void	ft_move_right(t_data *d)
{
	t_list	*door;

	door = which_door(d->lst_door, (int)(d->player_x - d->player_dir_y * 0.3),
			(int)(d->player_y + d->player_dir_x * 0.3));
	if (d->tab_map[(int)d->player_y][(int)d->player_x] == 'D'
		&& d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_y
		* 0.3)] != '1' && d->tab_map[(int)(d->player_y + d->player_dir_x * 0.3)]
		[(int)d->player_x] != '1')
		calcul_move(d, 3);
	else if (d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_y
		* 0.3)] == '0' && d->tab_map[(int)(d->player_y + d->player_dir_x * 0.3)]
		[(int)d->player_x] == '0')
		calcul_move(d, 3);
	else if (d->lst_door && door->is_open == true)
	{
		if (d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_y
			* 0.3)] != '1' && d->tab_map[(int)(d->player_y + d->player_dir_x
			* 0.3)][(int)d->player_x] != '1')
			calcul_move(d, 3);
	}
}
