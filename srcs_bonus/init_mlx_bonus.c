/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trobert <trobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/24 12:56:37 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/14 13:05:58 by trobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

void	check_img_size(t_data *data, t_mlx *mlx)
{
	int	sum;
	int	total;

	sum = mlx->n_wall.h * 4;
	total = mlx->n_wall.h + mlx->s_wall.h + mlx->e_wall.h + mlx->w_wall.h;
	if (sum != total)
		error_exit(data, "Textures height are not the same\n");
	sum = mlx->n_wall.w * 4;
	total = mlx->n_wall.w + mlx->s_wall.w + mlx->e_wall.w + mlx->w_wall.w;
	if (sum != total)
		error_exit(data, "Textures width are not the same\n");
	mlx->img_h = mlx->n_wall.h;
	mlx->img_w = mlx->w_wall.w;
	if (mlx->img_h != mlx->img_w)
		error_exit(data, "Width and height textures need to be the same size\n");
	if (mlx->img_h > 250 || mlx->img_w > 250)
		error_exit(data, "Textures too big\n");
}

void	init_img_data(t_data *data, t_img_data *img, char *path)
{
	t_mlx	*mlx;

	mlx = &data->mlx;
	img->endian = 0;
	img->xpm = mlx_xpm_file_to_image(mlx->mlx, path, &img->w, &img->h);
	if (!img->xpm)
		error_exit(data, "mlx_xpm_to_image function failed\n");
	img->addr = mlx_get_data_addr(img->xpm, &(img->bpp),
			&(img->size_line), &(img->endian));
	if (!img->addr)
		error_exit(data, "mlx_get_data_addr function failed\n");
}

static void	init_img_anim_wall(t_data *data, t_mlx *mlx)
{
	init_img_data(data, &mlx->d_wall, "./img/wooden_box.xpm");
	init_img_data(data, &data->anim.anim1, "img/xpm_navi50/navi50_0.xpm");
	init_img_data(data, &data->anim.anim2, "img/xpm_navi50/navi50_1.xpm");
	init_img_data(data, &data->anim.anim3, "img/xpm_navi50/navi50_2.xpm");
	init_img_data(data, &data->anim.anim4, "img/xpm_navi50/navi50_3.xpm");
	init_img_data(data, &data->anim.anim5, "img/xpm_navi50/navi50_4.xpm");
	init_img_data(data, &data->anim.anim6, "img/xpm_navi50/navi50_5.xpm");
	init_img_data(data, &data->anim.anim7, "img/xpm_navi50/navi50_6.xpm");
	init_img_data(data, &data->anim.anim8, "img/xpm_navi50/navi50_7.xpm");
	init_img_data(data, &data->anim.anim9, "img/xpm_navi50/navi50_8.xpm");
	init_img_data(data, &data->anim.anim10, "img/xpm_navi50/navi50_9.xpm");
	init_img_data(data, &data->anim.anim11, "img/xpm_navi50/navi50_10.xpm");
	init_img_data(data, &data->anim.anim12, "img/xpm_navi50/navi50_11.xpm");
}

void	check_screen_size(t_data *data, t_mlx *mlx)
{
	int	x;
	int	y;

	if (W_W < 200 || W_H < 200)
		error_exit(data, "Mlx window too small\n");
	mlx_get_screen_size(mlx->mlx, &x, &y);
	if (W_W > x || W_H > y)
		error_exit(data, "Mlx window bigger than screen size\n");
}

int	init_mlx(t_data *data, t_mlx *mlx)
{
	mlx->dataa = data;
	mlx->mlx = mlx_init();
	if (!mlx->mlx)
		return (0);
	check_screen_size(data, mlx);
	mlx->new_img.xpm = mlx_new_image(mlx->mlx, W_W, W_H);
	mlx->new_img.addr = mlx_get_data_addr(mlx->new_img.xpm, &(mlx->new_img.bpp),
			&(mlx->new_img.size_line), &(mlx->new_img.endian));
	init_img_data(data, &mlx->n_wall, data->path_n_texture);
	init_img_data(data, &mlx->s_wall, data->path_s_texture);
	init_img_data(data, &mlx->e_wall, data->path_e_texture);
	init_img_data(data, &mlx->w_wall, data->path_w_texture);
	init_img_anim_wall(data, mlx);
	check_img_size(data, mlx);
	check_img_size_anim(data);
	mlx->mlx_win = mlx_new_window(mlx->mlx, W_W, W_H, "CUB");
	mlx->w_key = false;
	mlx->a_key = false;
	mlx->s_key = false;
	mlx->d_key = false;
	mlx->left_key = false;
	mlx->right_key = false;
	return (1);
}
