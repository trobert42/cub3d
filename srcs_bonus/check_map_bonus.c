/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:38:32 by trobert           #+#    #+#             */
/*   Updated: 2022/12/13 18:13:27 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	check_char(t_data *data, char **map)
{
	int		i;
	int		j;

	i = -1;
	data->player_orientation = '\0';
	while (map[++i])
	{
		j = -1;
		while (map[i][++j])
		{
			if (ft_strchr("NESWD01 ", map[i][j]) == 0)
				return (print_error("Invalid character inside map\n"), 0);
			if (ft_strchr("NESW", map[i][j]))
			{
				if (data->player_orientation)
					return (print_error("Invalid nbr of player\n"), 0);
				data->player_orientation = map[i][j];
				data->player_x = j;
				data->player_y = i;
			}
		}
	}
	if (!data->player_orientation)
		return (print_error("Need to have one player\n"), 0);
	return (1);
}

int	check_around(t_data *data, char **map, int y, int x)
{
	if (y - 1 < 0 || map[y - 1][x] == ' ')
		return (0);
	if (x + 1 == data->w || map[y][x + 1] == ' ')
		return (0);
	if (y + 1 == data->h || map[y + 1][x] == ' ')
		return (0);
	if (x - 1 < 0 || map[y][x - 1] == ' ')
		return (0);
	if (x + 1 == data->w || y - 1 < 0 || map[y - 1][x + 1] == ' ')
		return (0);
	if (x + 1 == data->w || y + 1 == data->h || map[y + 1][x + 1] == ' ')
		return (0);
	if (x - 1 < 0 || y + 1 == data->h || map[y + 1][x - 1] == ' ')
		return (0);
	if (x - 1 < 0 || y - 1 < 0 || map[y - 1][x - 1] == ' ')
		return (0);
	return (1);
}

int	check_wall(t_data *data, char **map)
{
	int		x;
	int		y;

	y = -1;
	while (map[++y])
	{
		x = -1;
		while (map[y][++x])
		{
			if (map[y][x] == '0' && !check_around(data, map, y, x))
				return (0);
			if (map[y][x] == 'D' && !check_around(data, map, y, x))
				return (0);
			if (map[y][x] == data->player_orientation
				&& !check_around(data, map, y, x))
				return (0);
		}
	}
	return (1);
}

int	count_width(t_data *data, char *line)
{
	int	len;

	len = ft_strlen(line);
	if (len > data->w && line[len - 1] == '\n')
		data->w = ft_strlen(line) - 1;
	else if (len > data->w && line[len - 1] != '\n')
		data->w = ft_strlen(line);
	return (1);
}

int	count_height(t_data *data, char *path_map)
{
	char	*line;
	int		count;

	count = 0;
	data->fd = open(path_map, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		if ((count > 0 && !line_is_map(line)) || (line_is_map(line)
				&& data->flag == 1 && line[0] != '\n'))
			return (free(line), close(data->fd), 0);
		if (count > 0 && line[0] == '\n')
			data->flag = 1;
		else if (line_is_map(line) && data->flag == 0 && !(count == 0
				&& line[0] == '\n'))
			count += count_width(data, line);
		free(line);
	}
	return (close(data->fd), count);
}
