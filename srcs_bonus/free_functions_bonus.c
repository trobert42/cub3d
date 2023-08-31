/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:15 by trobert           #+#    #+#             */
/*   Updated: 2022/12/13 11:00:13 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

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

void	free_list(t_list **lst)
{
	t_list	*temp;
	t_list	*next;

	temp = *lst;
	while (temp)
	{
		next = temp->next;
		free(temp);
		temp = next;
	}
	*lst = NULL;
}

void	free_all(t_data *data)
{
	free_parsing(data);
	free_img_mlx(data, &data->mlx);
	if (data->ray)
		free(data->ray);
	if (data->lst_door)
		free_list(&data->lst_door);
	free((&data->mlx)->mlx);
	exit(0);
}
