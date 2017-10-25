/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_manage.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:47:32 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:56:44 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

void				create_image(t_inf *inf)
{
	t_img			*img;

	if (!(img = malloc(S_IMG)))
		exits(2, inf);
	img->pid = mlx_new_image(inf->mid, WIDTH, HEIGHT);
	img->str = mlx_get_data_addr(img->pid, &img->bpp, &img->len, &img->end);
	inf->img = img;
}

static void			filtr(char *to_manip, int i, char rgb[3], t_inf *inf)
{
	if (!inf->img->end)
	{
		i *= (inf->img->bpp / 8);
		to_manip[i + 0] = rgb[0];
		to_manip[i + 1] = rgb[1];
		to_manip[i + 2] = rgb[2];
	}
	else
	{
		i *= (inf->img->bpp / 8);
		to_manip[i + 0] = rgb[2];
		to_manip[i + 1] = rgb[1];
		to_manip[i + 2] = rgb[0];
	}
}

void				set_pixie(t_inf *inf, int x, int y, unsigned int color)
{
	char			rgb[3];
	char			*to_manip;
	int				i;
	int				len;

	i = 0;
	len = inf->img->len / (inf->img->bpp / 8);
	to_manip = inf->img->str;
	while (i <= 3)
	{
		rgb[i++] = color | 0x0000;
		color = color >> 8;
	}
	i = (y * len) + x;
	filtr(to_manip, i, rgb, inf);
}
