/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_parsing_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:59 by trobert           #+#    #+#             */
/*   Updated: 2022/12/14 13:00:09 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	count_char(char *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == c)
			count++;
		i++;
	}
	return (count);
}

int	count_size_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

void	get_colors_rgb(t_data *data)
{
	char	**tmp;

	tmp = ft_split(data->floor_rgb_str, ',');
	data->floor_rgb = (ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
		+ ft_atoi(tmp[2]);
	free_split(tmp);
	tmp = ft_split(data->ceiling_rgb_str, ',');
	data->ceiling_rgb = (ft_atoi(tmp[0]) << 16) + (ft_atoi(tmp[1]) << 8)
		+ ft_atoi(tmp[2]);
	free_split(tmp);
}

int	line_is_map(char *str)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	while (str[i])
	{
		if (str[i] == 'N' || str[i] == 'E' || str[i] == 'S' || str[i] == 'W')
		{
			i++;
			continue ;
		}
		if (str[i] != '1' && str[i] != '0' && str[i] != '\n' && str[i] != ' '
			&& str[i] != 'D')
			return (0);
		i++;
	}
	return (1);
}
