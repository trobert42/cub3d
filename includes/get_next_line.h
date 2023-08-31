/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:56:11 by ldinaut           #+#    #+#             */
/*   Updated: 2022/02/22 17:53:20 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>

char		*get_next_line(int fd);
char		*ft_strdupp(const char *s1, int index);
char		*ft_save_line(int i, char save[BUFFER_SIZE + 1], int fd);
char		*ft_strjoinn(char *save, char *line);
char		*ft_strjoin2(char *save, char *ret, char *line);

void		ft_update_save(char save[BUFFER_SIZE + 1], int index);

int			ft_strlenn(char *str);
int			ft_get_index(char *str);

#endif
