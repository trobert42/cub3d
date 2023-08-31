/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_charset.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 18:38:47 by trobert           #+#    #+#             */
/*   Updated: 2022/11/24 15:33:21 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

static int	ft_count_words(const char *str, char *charset)
{
	int		i;
	int		len;
	int		count;

	i = 0;
	count = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		while (str[i] && is_sep(str[i], charset))
			++i;
		if (str[i])
			++count;
		while (str[i] && !is_sep(str[i], charset))
			++i;
		++i;
	}
	return (count);
}

static char	*ft_strdup_index(const char *src, int start, int end)
{
	char	*copy;
	int		size;
	int		i;

	i = 0;
	size = (end - start);
	copy = malloc(sizeof(char) * (size + 1));
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = src[start + i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char	**ft_split2(char const *str, char *charset, char **tab)
{
	int		i;
	int		j;
	int		k;
	int		len;

	i = 0;
	k = 0;
	len = ft_strlen(str);
	while (i < len)
	{
		while (str[i] && is_sep(str[i], charset))
			++i;
		j = i;
		if (!str[i])
			break ;
		while (str[i] && !is_sep(str[i], charset))
			++i;
		tab[k] = ft_strdup_index(str, j, i++);
		if (!tab[k])
			return (ft_free(tab, k), NULL);
		++k;
	}
	tab[k] = 0;
	return (tab);
}

char	**ft_split_charset(char const *str, char *charset)
{
	char	**tab;

	if (!str)
		return (NULL);
	tab = malloc(sizeof(char *) * (ft_count_words(str, charset) + 1));
	if (!tab)
		return (NULL);
	tab = ft_split2(str, charset, tab);
	return (tab);
}
