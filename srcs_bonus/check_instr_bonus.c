/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_instr_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:31:18 by trobert           #+#    #+#             */
/*   Updated: 2022/12/14 13:41:05 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

int	check_first_char(char *s, char c)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(s);
	while (i < len)
	{
		while (s[i] && s[i] == ' ')
			i++;
		if (s[i] == c)
			return (1);
		else
			return (0);
	}
	return (0);
}

void	check_first_time_fd(t_data *d, char *path_map)
{
	d->fd = open(path_map, O_DIRECTORY);
	if (d->fd != -1)
	{
		close(d->fd);
		error_exit(d, "Not a file\n");
	}
	d->fd = open(path_map, O_RDONLY);
	if (d->fd < 0)
		error_exit(d, "Failed to open or map not found\n");
}

int	check_order_nbr_instr(t_data *d, char *path_map)
{
	char	*line;
	int		instr_count;

	instr_count = 0;
	check_first_time_fd(d, path_map);
	while (1)
	{
		line = get_next_line(d->fd);
		if (!line)
			break ;
		if (instr_count == 6 && !line_is_map(line))
			return (free(line), close(d->fd), print_error("map not valid\n"), 0);
		else if (ft_strncmp(line, "\n", 1) && !check_first_char(line, '1')
			&& instr_count < 6 && !check_first_char(line, ' '))
			instr_count++;
		else if (ft_strncmp(line, "\n", 1) && check_first_char(line, '1')
			&& instr_count != 6)
			return (free(line), close(d->fd), 0);
		free(line);
	}
	if (instr_count != 6)
		return (close(d->fd), print_error("Invalid instr or order\n"), 0);
	return (close(d->fd), 1);
}

int	is_valid_instr(t_data *data, char *path_map)
{
	char	*line;
	int		i;

	i = 0;
	data->fd = open(path_map, O_RDONLY);
	while (i < 6)
	{
		line = get_next_line(data->fd);
		if (line && ft_strncmp(line, "\n", 1))
		{
			set_all_texture(data, line);
			i++;
		}
		if (line)
			free(line);
	}
	close(data->fd);
	if (!check_all_texture(data))
		return (0);
	return (1);
}
