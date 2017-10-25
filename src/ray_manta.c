/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 19:53:49 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 09:59:50 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

static int			iterations(long double coords[], t_inf inf)
{
	long double		pos[4];
	int				i;
	double			tmp;

	pos[CR] = 0.84;
	pos[CI] = 0.31;
	pos[ZR] = coords[X];
	pos[ZI] = coords[Y];
	i = 0;
	while (i < inf.def && (PYTH(pos[ZR], pos[ZI]) < 4))
	{
		tmp = pos[ZR];
		pos[ZR] = pos[ZR] * pos[ZR] - pos[ZI] * pos[ZR] * pos[ZI] + pos[CR];
		pos[ZI] = pos[ZR] * tmp + pos[CI];
		i++;
	}
	return (i);
}

void				otfif(t_inf inf)
{
	long double		coords[6];
	int				itera;

	coords[0] = inf.xdlim;
	while ((coords[0] += ((inf.xulim - inf.xdlim) /
					(double)(WIDTH + 1))) <= inf.xulim)
	{
		coords[1] = inf.ydlim;
		while ((coords[1] += ((inf.yulim - inf.ydlim) /
						(double)(HEIGHT + 1))) <= inf.yulim)
		{
			if ((TRX(coords[0], inf) < WIDTH && TRX(coords[0], inf) >= 0) &&
					(TRY(coords[1], inf) < HEIGHT && TRY(coords[1], inf) >= 0))
			{
				itera = iterations(coords, inf);
				set_pixie(&inf, TRX(coords[X], inf), TRY(coords[Y], inf),
					((itera * 5) << 8) + (itera * 5));
			}
		}
	}
}
