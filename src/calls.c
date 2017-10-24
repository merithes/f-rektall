/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:17:32 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/24 20:40:29 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

void				restate_infos(t_inf *inf)
{
	inf->def = MX_IT;
	inf->safe = 0;
	inf->color = 0x000101;
	inf->xdlim = -2;
	inf->xulim = 2;
	inf->ydlim = -2;
	inf->yulim = 2;
	inf->zoomey = 0;
	inf->revert = 0;
}

void				call_fractal(t_inf *inf)
{
	if (!inf)
		exit(-1);
	if (inf->def > 325)
	   inf->def = 325;
	if (inf->switcher)
	{
		inf->switcher = 0;
		restate_infos(inf);
	}
	if (inf->fractal & MANDL)
		mandelbrot(*inf);
	else if (inf->fractal & JULIA)
		julia(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	ft_bzero(inf->img->str, inf->img->len * HEIGHT);
}
