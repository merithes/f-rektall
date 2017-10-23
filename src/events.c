/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/23 08:17:43 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/23 11:41:31 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

int					pull_cursor(int x, int y, void *param)
{
	t_inf			*inf;
	
	inf = (t_inf *)param;
	if (inf->safe++ % 6)
		return 0;
	x = (x > WIDTH) ? WIDTH : x;
	x = (x < 0) ? 0 : x;
	y = (y > HEIGHT) ? HEIGHT : y;
	y = (y < 0) ? 0 : y;
	inf->color = (int)((x / (float)WIDTH) * 2) * 0x010000;
	inf->color += (int)((y / (float)HEIGHT) * 2) * 0x000100;
	keyset(inf, -1);
	return (0);
}

int					pull_ckey(int kc, int x, int y, void *param)
{
	t_inf			*inf;
	int				moreless;
	double			ratio;

	inf = (t_inf *)param;
	moreless = 0;
	ratio = (HEIGHT / (double)WIDTH);
	if (kc == 5 || kc == 1)
	{
		inf->zoomey += (kc == 5) ? -1 : 1;
		moreless = (kc == 5) ? -1  : 1;
		moreless *= inf->revert ? -1 : 1;
	}
	inf->ydlim += ((inf->yulim - inf->ydlim) / (2 * moreless))
		* ratio * (y / (double)HEIGHT);
	inf->yulim -= ((inf->yulim - inf->ydlim) / (2 * moreless))
		* ratio * ((HEIGHT - y) / (double)HEIGHT);
	inf->xdlim += ((inf->xulim - inf->xdlim) / (2 * moreless))
		* (x / (double)WIDTH);
	inf->xulim -= ((inf->xulim - inf->xdlim) / (2 * moreless))
		* ((WIDTH - x) / (double)WIDTH);
	mandelbrot(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (x - x + y - y);
}
