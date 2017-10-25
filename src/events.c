/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 08:17:43 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:47:05 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

int					pull_cursor(int x, int y, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	if (!(inf->fractal & JULIA))
		return (0);
	if (!(inf->safe++ % 6) || inf->lock)
		return (0);
	x = (x > WIDTH) ? WIDTH : x;
	x = (x < 0) ? 0 : x;
	y = (y > HEIGHT) ? HEIGHT : y;
	y = (y < 0) ? 0 : y;
	if (!inf->lock)
	{
		inf->ji = (x / (double)WIDTH);
		inf->jr = (y / (double)WIDTH);
	}
	call_fractal(inf);
	return (0);
}

void				zoom_ft(t_inf *inf, int moreless, int x, int y)
{
	if (inf->zoomey <= 60 || (inf->zoomey > 60 && moreless < 0))
	{
		inf->ydlim += ((inf->yulim - inf->ydlim) / (2 * moreless))
			* (y / (double)HEIGHT);
		inf->yulim -= ((inf->yulim - inf->ydlim) / (2 * moreless))
			* ((HEIGHT - y) / (double)HEIGHT);
		inf->xdlim += ((inf->xulim - inf->xdlim) / (2 * moreless))
			* (x / (double)WIDTH);
		inf->xulim = inf->xdlim + (inf->yulim - inf->ydlim);
	}
	else
		inf->zoomey = 60;
}

int					pull_ckey(int kc, int x, int y, void *param)
{
	t_inf			*inf;
	int				moreless;

	inf = (t_inf *)param;
	moreless = 1;
	if (kc == 5 || kc == 1 || kc == 4)
	{
		moreless = (kc == 5) ? -1 : 1;
		moreless *= inf->revert ? -1 : 1;
		inf->zoomey += moreless;
	}
	zoom_ft(inf, moreless, x, y);
	call_fractal(inf);
	return (0);
}
