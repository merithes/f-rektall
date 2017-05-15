#include "hfractol.h"

void				mandelbrot(t_inf inf)
{
	float			coords[2];
	complex double	p[2];
	int				itera;

	coords[0] = -1;
	while((coords[0] += (2 / (float)(WIDTH + 10))) <= 4)
	{
		coords[1] = -1;
		while ((coords[1] += (2 / (float)(HEIGHT + 10))) <= 4)
		{
			itera = 0;
			p[0] = CMPLX(coords[0], coords[1]);
			p[1] = 0;
			while(cabs(p[1]) < 2 && itera++ < inf.def)
				p[1] = p[1] * p[1] + p[0];
			itera--;
			if ((TRX(coords[0]) <= WIDTH && TRX(coords[0]) >= 0) &&
					(TRY(coords[1]) <= HEIGHT && TRY(coords[1]) >= 0))
				set_pixie(&inf, TRX(coords[0]), TRY(coords[1]),
					0x000101 * (int)((itera / (float)inf.def) * 255));
		}
	}
}
