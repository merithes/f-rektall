/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractals.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 18:07:39 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:45:33 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

static unsigned int	iterations(int max, long double coords[2])
{
	long double		p[4];
	int				i;
	double			tmp;

	p[ZI] = 0;
	p[ZR] = 0;
	p[CR] = coords[X];
	p[CI] = coords[Y];
	i = 0;
	while (i < max && PYTH(p[ZI], p[ZR]) < 4)
	{
		tmp = powl(p[ZI], 3) - 3 * p[ZI] * powl(p[ZR], 2) + p[CI];
		p[ZR] = 2 * exp2l(p[ZI]) * p[ZR] - powl(p[ZR], 3) + p[CR];
		p[ZI] = tmp;
		i++;
	}
	return (i);
}

void				otthr(t_inf inf)
{
	long double		coords[2];
	int				itera;

	coords[X] = inf.xdlim;
	while ((coords[X] += ((inf.xulim - inf.xdlim) /
					(double)(WIDTH + 1))) <= inf.xulim)
	{
		coords[Y] = inf.ydlim;
		while ((coords[Y] += ((inf.yulim - inf.ydlim) /
						(double)(HEIGHT + 1))) <= inf.yulim)
		{
			if ((TRX(coords[X], inf) < WIDTH && TRX(coords[X], inf) >= 0) &&
					(TRY(coords[Y], inf) < HEIGHT && TRY(coords[Y], inf) >= 0))
			{
				itera = iterations(inf.def, coords);
				set_pixie(&inf, TRX(coords[X], inf) - TRX(inf.xulim, inf) * 0,
						TRY(coords[Y], inf) - TRY(inf.yulim, inf) * 0,
							((itera * 5) << 16) + (itera << 8) + itera);
			}
		}
	}
}
