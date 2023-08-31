/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit_functions_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 16:22:39 by trobert           #+#    #+#             */
/*   Updated: 2022/12/06 21:50:18 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	print_error(char *err_msg)
{
	write(2, "Error\n", 6);
	write(2, err_msg, ft_strlen(err_msg));
}

void	error_exit(t_data *data, char *err_msg)
{
	if (err_msg)
		print_error(err_msg);
	free_all(data);
	exit(EXIT_FAILURE);
}
