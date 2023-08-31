/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 15:55:05 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/06 15:15:56 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed.h"

int	main(int ac, char *av[])
{
	t_data	data;

	if (ac != 2 || (ac == 2 && !av[1][0]))
		return (print_error("Usage : ./cubed map_name.cub\n"), 0);
	init_var(&data);
	check_config_file(&data, av[1]);
	if (!init_mlx(&data, &data.mlx))
		error_exit(&data, "mlx_init function failed\n");
	launch_game(&data);
	ft_hook(&data);
	mlx_loop(data.mlx.mlx);
	return (0);
}
