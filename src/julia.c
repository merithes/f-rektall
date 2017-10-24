/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:53:49 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/24 21:20:45 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

static int			iterations(long double coords[], t_inf inf)
{
	long double		pos[4];
	int				i;
	double			tmp;

	pos[CR] = inf.jr;
	pos[CI] = -inf.ji;
	pos[ZR] = coords[X];
	pos[ZI] = coords[Y];
	i = 0;
	while (i < inf.def && (PYTH(pos[ZR], pos[ZI]) < 4))
	{
		tmp = pos[ZR];
		pos[ZR] = pos[ZR]  * pos[ZR] - pos[ZI] * pos[ZI] + pos[CR];
		pos[ZI] = 2 * pos[ZI] * tmp + pos[CI];
		i++;
	}
	return (i);
}

void				julia(t_inf inf)
{
	long double coords[6];
	int itera;

	coords[1] = inf.xdlim;
	while ((coords[0] += ((inf.xulim - inf.xdlim) / (double)(WIDTH + 1))) <= inf.xulim)
	{
		coords[1] = inf.ydlim;
		while ((coords[1] += ((inf.yulim - inf.ydlim) / (double)(HEIGHT + 1))) <= inf.yulim)
		{
			if ((TRX(coords[0], inf) < WIDTH && TRX(coords[0], inf) >= 0) &&
					(TRY(coords[1], inf) < HEIGHT && TRY(coords[1], inf) >= 0))
			{
				itera = iterations(coords, inf);
				set_pixie(&inf, TRX(coords[X], inf), TRY(coords[Y], inf),
							((itera * 10) << 16) + (itera * 7));
			}
		}
	}
}
