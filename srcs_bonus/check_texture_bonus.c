/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_texture_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:24:29 by trobert           #+#    #+#             */
/*   Updated: 2022/12/12 08:40:26 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	check_all_texture(t_data *data)
{
	if (!data->path_n_texture)
		return (print_error("Failed to open or find path_n_texture\n"), 0);
	if (!data->path_e_texture)
		return (print_error("Failed to open or find path_e_texture\n"), 0);
	if (!data->path_s_texture)
		return (print_error("Failed to open or find path_s_texture\n"), 0);
	if (!data->path_w_texture)
		return (print_error("Failed to open or find path_w_texture\n"), 0);
	if (!data->floor_rgb_str)
		return (print_error("Incorrect instruction for floor color\n"), 0);
	if (!data->ceiling_rgb_str)
		return (print_error("Incorrect instruction for ceiling color\n"), 0);
	get_colors_rgb(data);
	return (1);
}

char	*get_texture_str(t_data *data, char *line)
{
	int		i;
	int		fd;
	char	**tmp;
	char	*path;

	i = 0;
	tmp = ft_split(line, ' ');
	while (tmp[1][i] && tmp[1][i] != '\n' && tmp[1][i] != '\t')
		i++;
	path = ft_substr(tmp[1], 0, i);
	if (!ft_strncmp("NO", tmp[0], 2) || !ft_strncmp("SO", tmp[0], 2)
		|| !ft_strncmp("WE", tmp[0], 2) || !ft_strncmp("EA", tmp[0], 2))
	{
		fd = open(path, O_RDONLY);
		if (fd < 0)
		{
			free(line);
			free(path);
			free_split(tmp);
			error_exit(data, "Failed to open or texture not found\n");
		}
		close(fd);
	}
	free_split(tmp);
	return (path);
}

int	check_rgb_str(char *rgb)
{
	char	**tmp;
	int		i;
	int		j;

	i = -1;
	j = -1;
	tmp = ft_split_charset(rgb, ",\n\t");
	if (count_size_tab(tmp) != 3 || count_char(rgb, ',') != 2)
		return (free_split(tmp), 0);
	while (tmp[++i])
	{
		j = -1;
		while (tmp[i][++j])
		{
			if (!ft_isdigit(tmp[i][j]))
				return (free_split(tmp), 0);
		}
		if (ft_strlen(tmp[i]) > 3 || ft_atoi(tmp[i]) < 0
			|| ft_atoi(tmp[i]) > 255)
			return (free_split(tmp), 0);
	}
	return (free_split(tmp), 1);
}

int	check_first_keyword(char *line, char *keyword)
{
	char	**tmp;
	int		i;

	i = 0;
	tmp = ft_split_charset(line, " \n");
	while (tmp[i])
		i++;
	if (i != 2)
		return (free_split(tmp), 0);
	if ((keyword[0] == 'F' || keyword[0] == 'C') && !check_rgb_str(tmp[1]))
		return (free_split(tmp), 0);
	if (ft_strncmp(tmp[0], keyword, ft_strlen(tmp[0])) == 0)
		return (free_split(tmp), 1);
	return (free_split(tmp), 0);
}

void	set_all_texture(t_data *data, char *line)
{
	if (!data->path_n_texture && check_first_keyword(line, "NO"))
		data->path_n_texture = get_texture_str(data, line);
	else if (!data->path_e_texture && check_first_keyword(line, "EA"))
		data->path_e_texture = get_texture_str(data, line);
	else if (!data->path_s_texture && check_first_keyword(line, "SO"))
		data->path_s_texture = get_texture_str(data, line);
	else if (!data->path_w_texture && check_first_keyword(line, "WE"))
		data->path_w_texture = get_texture_str(data, line);
	else if (!data->floor_rgb_str && check_first_keyword(line, "F"))
		data->floor_rgb_str = get_texture_str(data, line);
	else if (!data->ceiling_rgb_str && check_first_keyword(line, "C"))
		data->ceiling_rgb_str = get_texture_str(data, line);
}
