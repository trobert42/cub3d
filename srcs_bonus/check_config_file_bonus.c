/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_config_file_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:25:16 by trobert           #+#    #+#             */
/*   Updated: 2022/12/14 13:33:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	check_extension(char *path_map)
{
	int	size;

	size = ft_strlen(path_map);
	if (size <= 3)
		return (0);
	if (path_map[size - 1] != 'b')
		return (0);
	if (path_map[size - 2] != 'u')
		return (0);
	if (path_map[size - 3] != 'c')
		return (0);
	if (path_map[size - 4] != '.')
		return (0);
	return (1);
}

void	write_map(t_data *data, char *line, int i)
{
	int	j;
	int	len;

	j = 0;
	if (line[ft_strlen(line) - 1] == '\n')
		len = ft_strlen(line) - 1;
	else
		len = ft_strlen(line);
	data->tab_map[i] = malloc(sizeof(char) * data->w + 1);
	if (!data->tab_map[i])
		error_exit(data, "Malloc during parsing has failed\n");
	while (j < len)
	{
		data->tab_map[i][j] = line[j];
		j++;
	}
	while (j < data->w)
		data->tab_map[i][j++] = ' ';
	data->tab_map[i][j] = '\0';
}

void	read_map(t_data *data, char *path_map)
{
	char	*line;
	int		count;
	int		i;

	i = 0;
	count = 0;
	data->h = count_height(data, path_map);
	if (data->h == 0 || data->w == 0 || !check_sizemap(data))
		error_exit(data, "Invalid map or too big ma(c)\n");
	data->tab_map = malloc(sizeof(char *) * (data->h + 1));
	if (!data->tab_map)
		error_exit(data, "Malloc during parsing has failed\n");
	data->fd = open(path_map, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		else if (line_is_map(line) && !(count == 0 && line[0] == '\n'))
			write_map(data, line, i++);
		free(line);
	}
	data->tab_map[i] = 0;
	close(data->fd);
}

int	check_sizemap(t_data *data)
{
	if (data->w > 400 && data->h > 400)
		return (0);
	return (1);
}

void	check_config_file(t_data *data, char *path_map)
{
	if (!check_extension(path_map))
		error_exit(data, "Invalid extension name\n");
	if (!check_order_nbr_instr(data, path_map))
		error_exit(data, NULL);
	if (!is_valid_instr(data, path_map))
		error_exit(data, NULL);
	read_map(data, path_map);
	if (!check_char(data, data->tab_map))
		error_exit(data, NULL);
	if (!check_wall(data, data->tab_map))
		error_exit(data, "Invalid map: not surrounded by walls\n");
}
