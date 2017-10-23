#include "hfractol.h"

t_inf				*set_inf(void)
{
	t_inf			*outp;

	if (!(outp = malloc(S_INF)))
		return (NULL);
	outp->mid = NULL;
	outp->wid = NULL;
	outp->img = NULL;
	outp->def = MX_IT;
	outp->mid = mlx_init();
	outp->wid = mlx_new_window(outp->mid, WIDTH, HEIGHT, TITLE);
	outp->safe = 0;
	outp->color = 0x000101;
	outp->xdlim = -2;
	outp->xulim = 2;
	outp->ydlim = -2;
	outp->yulim = 2;
	outp->zoomey = 0;
	outp->revert = 0;
	create_image(outp);
	return (outp);
}

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
		tmp = p[ZI] * p[ZI] - p[ZR] * p[ZR] + p[CR];
		p[ZR] = ((p[ZI] * p[ZR]) * 2)  + p[CI];
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
							((itera * 5 ) << 16) + (itera * 5));
			}
		}
	}
}


