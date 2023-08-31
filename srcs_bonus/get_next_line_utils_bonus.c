/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 22:16:46 by ldinaut           #+#    #+#             */
/*   Updated: 2022/11/23 17:41:54 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	ft_update_save(char save[BUFFER_SIZE + 1], int index)
{
	int	i;

	i = 0;
	index++;
	while (save[index])
	{
		save[i] = save[index];
		index++;
		i++;
	}
	while (save[i])
	{
		save[i] = '\0';
		i++;
	}
}

char	*ft_strdupp(const char *s1, int index)
{
	int			i;
	char		*dest;

	i = 0;
	dest = malloc(sizeof(char) * (index + 1));
	if (!dest)
		return (NULL);
	while (i < index)
	{
		dest[i] = s1[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int	ft_get_index(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (i);
}

int	ft_strlenn(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] != '\0')
		i++;
	return (i);
}
