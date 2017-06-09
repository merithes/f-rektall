#include "hfractol.h"

unsigned int		iterations(int max, long double coords[2])
{
	long double		p[4];
	int				i;
	double			tmp;

	i = 0;
	p[CR] = coords[X];
	p[CI] = coords[Y];
	p[ZI] = 0;
	p[ZR] = 0;
	while (i < max && PYTH(p[ZI], p[ZR]) < 4)
	{
		tmp = p[ZI]*p[ZI] - p[ZR]*p[ZR] + p[CR];
		p[ZR] = 2*p[ZI]*p[ZR] + p[CI];
		p[ZI] = tmp;
		i++;
	}
	return (i);
}

void				mandelbrot(t_inf inf)
{
	long double		coords[2];
	long double		lim[2];
	int				itera;

	ft_bzero(inf.img->str, inf.img->len * HEIGHT);
	coords[0] = inf.xdlim;
	lim[X] = inf.xdlim;
	lim[Y] = inf.ydlim;
	while((coords[0] += ((inf.xulim - inf.xdlim) / (double)(WIDTH + 1))) <= inf.xulim)
	{
		coords[1] = inf.ydlim;
		while ((coords[1] += ((inf.yulim - inf.ydlim) / (double)(HEIGHT + 1))) <= inf.yulim)
		{
			if ((TRX(coords[0], inf) < WIDTH && TRX(coords[0], inf) >= 0) &&
					(TRY(coords[1], inf) < HEIGHT && TRY(coords[1], inf) >= 0))
			{
				itera = iterations(inf.def, coords);
				set_pixie(&inf, TRX(coords[0], inf) - TRX(lim[X], inf) * 0, 
						TRY(coords[1], inf) - TRY(lim[Y], inf) * 0,
							inf.color * itera
						+ DEF_COL * (int)((itera / (float)inf.def) * 100));
			}
		}
	}
	set_pixie(&inf, 25, 25, 0xFFFFFF);
	printf("modd:(%f:%f), (%f;%f)\n", inf.xdlim, inf.xulim, inf.ydlim, inf.yulim);
}
