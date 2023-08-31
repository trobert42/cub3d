/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   doors_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/05 17:17:14 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 18:01:56 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

t_list	*get_door(t_list *lst, int id)
{
	t_list	*start;
	t_list	*door;

	start = lst;
	while (lst)
	{
		if (lst->id == id)
		{
			door = lst;
			lst = start;
			return (door);
		}
		lst = lst->next;
	}
	lst = start;
	return (lst);
}

int	find_id_door(t_list *lst, int x, int y)
{
	t_list	*start;
	int		id;

	id = -1;
	start = lst;
	while (lst)
	{
		if (lst->x == x && lst->y == y)
		{
			id = lst->id;
			lst = start;
			return (id);
		}
		lst = lst->next;
	}
	lst = start;
	return (id);
}

void	get_door_collision(t_data *data)
{
	double	pos_point_x;
	double	pos_point_y;
	int		hit;

	pos_point_x = data->player_x;
	pos_point_y = data->player_y;
	hit = 0;
	while (hit == 0)
	{
		pos_point_x += data->player_dir_x;
		pos_point_y += data->player_dir_y;
		if (pos_point_x < 0 || pos_point_y < 0 || (int)pos_point_x < data->w
			|| (int)pos_point_x < data->h)
			hit = -1;
		if (data->tab_map[(int)pos_point_y][(int)pos_point_x] == 'D')
		{
			data->first_collision_x = pos_point_x;
			data->first_collision_y = pos_point_y;
			hit = 1;
		}
	}
}

t_list	*which_door(t_list *lst, int x, int y)
{
	t_list	*start;
	t_list	*door;

	start = lst;
	while (lst)
	{
		if (lst->x == x && lst->y == y)
		{
			door = lst;
			lst = start;
			return (door);
		}
		lst = lst->next;
	}
	lst = start;
	return (lst);
}

void	check_open(t_data *data, t_ray *ray)
{
	t_list	*door;
	int		id;

	get_door_collision(data);
	id = find_id_door(data->lst_door, data->first_collision_x,
			data->first_collision_y);
	if (id == -1)
		return ;
	else
	{
		door = get_door(data->lst_door, id);
		if (door->is_open == true && data->tab_map[(int)data->player_y]
			[(int)data->player_x] == 'D')
			return ;
		if ((ray->hit == 2 && ray->wall_dist < 7.0) || (ray->hit == 1
				&& ray->wall_dist < 7.0 && door->is_open == true))
		{
			if (door->is_open == false)
				door->is_open = true;
			else
				door->is_open = false;
		}
	}
}
