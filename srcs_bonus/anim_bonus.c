/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anim_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ldinaut <ldinaut@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/07 15:58:16 by ldinaut           #+#    #+#             */
/*   Updated: 2022/12/12 17:47:14 by ldinaut          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cubed_bonus.h"

static int	get_colors_transparence(t_img_data img, int x, int y)
{
	int	i;
	int	j;
	int	color;

	i = (img.h - x) * 4;
	j = 0;
	while (j < y)
	{
		i += img.size_line;
		j++;
	}
	color = (img.addr[i + 2] * 256 * 256) + (img.addr[i + 1] * 256)
		+ img.addr[i];
	return (color);
}

void	put_pixel_anim_into_img(t_data *data, t_img_data animg, int x1, int y1)
{
	int	x;
	int	y;
	int	color;

	y = 0;
	while (y < animg.h)
	{
		x = 0;
		while (x < animg.h)
		{
			color = get_colors_transparence(animg, x, y);
			if (color != 0)
				put_pixel_into_img(data, x + x1, y + y1, color);
			x++;
		}
		y++;
	}
}

void	anim_loop(t_data *data)
{
	if (data->i_anim <= 4)
		put_pixel_anim_into_img(data, data->anim.anim1, 200, 200);
	if (data->i_anim > 4 && data->i_anim <= 8)
		put_pixel_anim_into_img(data, data->anim.anim2, 205, 205);
	if (data->i_anim > 8 && data->i_anim <= 12)
		put_pixel_anim_into_img(data, data->anim.anim3, 210, 210);
	if (data->i_anim > 12 && data->i_anim <= 16)
		put_pixel_anim_into_img(data, data->anim.anim4, 215, 215);
	if (data->i_anim > 16 && data->i_anim <= 20)
		put_pixel_anim_into_img(data, data->anim.anim5, 220, 220);
	if (data->i_anim > 20 && data->i_anim <= 24)
		put_pixel_anim_into_img(data, data->anim.anim6, 225, 225);
	if (data->i_anim > 24 && data->i_anim <= 28)
		put_pixel_anim_into_img(data, data->anim.anim7, 230, 230);
	if (data->i_anim > 28 && data->i_anim <= 32)
		put_pixel_anim_into_img(data, data->anim.anim8, 225, 225);
	if (data->i_anim > 32 && data->i_anim <= 36)
		put_pixel_anim_into_img(data, data->anim.anim9, 220, 220);
	if (data->i_anim > 36 && data->i_anim <= 40)
		put_pixel_anim_into_img(data, data->anim.anim10, 215, 215);
	if (data->i_anim > 40 && data->i_anim <= 44)
		put_pixel_anim_into_img(data, data->anim.anim11, 210, 210);
	if (data->i_anim > 44 && data->i_anim <= 48)
		put_pixel_anim_into_img(data, data->anim.anim12, 205, 205);
}
