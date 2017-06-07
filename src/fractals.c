#include "hfractol.h"

void				mandelbrot(t_inf inf)
{
	float			coords[2];
	complex double	p[2];
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
				itera = 0;
				p[0] = CMPLX(coords[0], coords[1]);
				p[1] = 0;
				while(cabs(p[1]) < 2 && itera++ < inf.def)
					p[1] = p[1] * p[1] + p[0];
				itera--;
					set_pixie(&inf, TRX(coords[0], inf), TRY(coords[1], inf),
						0x000101 * (int)((itera / (float)inf.def) * 255));
			}
		}
	}
	printf("modd:(%f:%f), (%f;%f)\n", inf.xdlim, inf.xulim, inf.ydlim, inf.yulim);
}
