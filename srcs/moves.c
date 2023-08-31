/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/25 18:42:27 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/07 18:18:42 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

void	ft_move_front(t_data *d)
{
	if (d->tab_map[(int)(d->player_y + d->player_dir_y * 0.3)][(int)d->player_x]
		== '0' && d->tab_map[(int)d->player_y][(int)(d->player_x
		+ d->player_dir_x * 0.3)] == '0')
	{
		d->player_x += d->player_dir_x * SPEED;
		d->player_y += d->player_dir_y * SPEED;
	}
}

void	ft_move_back(t_data *d)
{
	if (d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_x * 0.3)]
		== '0' && d->tab_map[(int)(d->player_y - d->player_dir_y * 0.3)]
		[(int)d->player_x] == '0')
	{
		d->player_x -= d->player_dir_x * SPEED;
		d->player_y -= d->player_dir_y * SPEED;
	}
}

void	ft_move_left(t_data *d)
{
	if (d->tab_map[(int)d->player_y][(int)(d->player_x + d->player_dir_y * 0.3)]
		== '0' && d->tab_map[(int)(d->player_y - d->player_dir_x * 0.3)]
		[(int)d->player_x] == '0')
	{
		d->player_x += SPEED * d->player_dir_y;
		d->player_y -= SPEED * d->player_dir_x;
	}
}

void	ft_move_right(t_data *d)
{
	if (d->tab_map[(int)d->player_y][(int)(d->player_x - d->player_dir_y * 0.3)]
		== '0' && d->tab_map[(int)(d->player_y + d->player_dir_x * 0.3)]
		[(int)d->player_x] == '0')
	{
		d->player_x -= SPEED * d->player_dir_y;
		d->player_y += SPEED * d->player_dir_x;
	}
}
