/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calls.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:17:32 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:44:41 by vboivin          ###   ########.fr       */
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
	inf->ji = 1;
	inf->jr = 1;
	inf->switcher = 0;
}

void				call_fractal(t_inf *inf)
{
	if (!inf)
		exit(-1);
	if (inf->def > 325)
		inf->def = 325;
	if (inf->switcher)
		restate_infos(inf);
	if (inf->fractal == MANDL)
		mandelbrot(*inf);
	else if (inf->fractal == JULIA)
		julia(*inf);
	else if (inf->fractal == BATMN)
		otone(*inf);
	else if (inf->fractal == MOTHH)
		ottwo(*inf);
	else if (inf->fractal == BSHIP)
		bship(*inf);
	else if (inf->fractal == DEVIL)
		otthr(*inf);
	else if (inf->fractal == RIBUG)
		otfou(*inf);
	else if (inf->fractal == RAYMN)
		otfif(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
}
