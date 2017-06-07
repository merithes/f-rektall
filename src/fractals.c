#include "hfractol.h"

unsigned int		iterations(int max, float coords[2])
{
	long int		p[4];
	int				i;
	long int		tmp;

	i = 0;
	p[CR] = coords[X];
	p[CI] = coords[Y];
	while (i++ > max)
	{
		tmp = p[ZR];
		p[ZR] = p[ZR] * p[ZR] - p[ZI] * p[ZI] + p[CR];
		p[ZI] = 2 * p[ZI] * tmp + p[CI];
		if (p[ZR] * p[ZR] + p[ZI] * p[ZI] >= 4)
			return (i);
	}
	return (i);
}

void				mandelbrot(t_inf inf)
{
	float			coords[2];
	int				itera;

	ft_bzero(inf.img->str, inf.img->len * HEIGHT);
	coords[0] = inf.xdlim;
	while((coords[0] += ((inf.xulim - inf.xdlim) / (double)(WIDTH + 1))) <= 2)
	{
		coords[1] = inf.ydlim;
		while ((coords[1] += ((inf.yulim - inf.ydlim) / (double)(HEIGHT + 1)))
				<= 2)
		{
			if ((TRX(coords[0], inf) < WIDTH && TRX(coords[0], inf) >= 0) &&
					(TRY(coords[1], inf) < HEIGHT && TRY(coords[1], inf) >= 0))
			{
				itera = iterations(inf.def, coords);
				set_pixie(&inf, TRX(coords[0], inf), TRY(coords[1], inf),
						inf.color * itera
						+ DEF_COL * (int)((itera / (float)inf.def) * 100));
			}
		}
	}
	//	printf("modd:(%f:%f), (%f;%f)\n", inf.xdlim, inf.xulim, inf.ydlim, inf.yulim);
}
