/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_keys.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:55:02 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:46:23 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

void				move(t_inf *inf, int kc)
{
	if (kc == 0)
		inf->xdlim -= (inf->xulim - inf->xdlim) / 20;
	if (kc == 2)
		inf->xdlim += (inf->xulim - inf->xdlim) / 20;
	if (kc == 0)
		inf->xulim -= (inf->xulim - inf->xdlim) / 20;
	if (kc == 2)
		inf->xulim += (inf->xulim - inf->xdlim) / 20;
	if (kc == 13)
		inf->ydlim -= (inf->yulim - inf->ydlim) / 20;
	if (kc == 1)
		inf->ydlim += (inf->yulim - inf->ydlim) / 20;
	if (kc == 13)
		inf->yulim -= (inf->yulim - inf->ydlim) / 20;
	if (kc == 1)
		inf->yulim += (inf->yulim - inf->ydlim) / 20;
}

void				keyset(t_inf *inf, int kc)
{
	int				i;

	i = 0;
	if (kc == 0 || kc == 2 || kc == 1 || kc == 13)
		move(inf, kc);
	else if (kc == 37)
		inf->lock = inf->lock ? 0 : 1;
	else if (kc == 7)
		inf->switcher = 1;
	else if (kc == 15 && ++i)
		inf->revert = inf->revert ? 0 : 1;
	else if (kc == 65365 || kc == 65366 || kc == 116 || kc == 121)
		inf->def += (kc == 65366 || kc == 116) ? DIFF_IT : -DIFF_IT;
	inf->def = (inf->def < 0) ? 0 : inf->def;
	if (inf->def && inf->fractal & JULIA)
		inf->def = (inf->def >= 185) ? 185 : inf->def;
	if (!i)
		call_fractal(inf);
}

int					pull_event(int kc, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	if (kc == 65307 || kc == 53)
		exits(1, inf);
	else
		keyset(inf, kc);
	return (0);
}
