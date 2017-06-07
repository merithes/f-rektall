#include "hfractol.h"

void			keyset(t_inf *inf, int kc)
{
	int i;

	i = 0;
	if (kc == 65365 || kc == 65366 || kc == 116 || kc == 121)
		inf->def += (kc == 65366 || kc == 116) ? DIFF_IT : -DIFF_IT;
	else if (kc == 65362 || kc == 65364)
		inf->ydlim += (kc == 65362) ? DIFF_MARG : -DIFF_MARG;
	else if (kc == 65361 || kc == 65363)
		inf->xdlim += (kc == 65361) ? DIFF_MARG : -DIFF_MARG;
	else if (kc == 113 || kc == 100)
		inf->xulim += (kc == 113) ? DIFF_Y : -DIFF_Y;
	else if (kc == 42 && ++i)
		ft_bzero(inf->img->str, inf->img->len * HEIGHT);
	else if (kc != 0)
		i++;
	inf->def = (inf->def < 0) ? 0 : inf->def;
	if (!i)
		mandelbrot(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
}

int					pull_event(int kc, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	if (kc == 65307 || kc == 53)
		exits(1, inf);
	else
		keyset(inf, kc);
	printf("%d\n", kc);
//	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (0);
}

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
	inf->color = (int)((x / (float)WIDTH) * 5) * 0x010000;
	inf->color += (int)((y / (float)HEIGHT) * 5) * 0x000100;
	keyset(inf, 0);
//	printf("%f\t", (x / (float)WIDTH) * 50);
//	printf("%f\n", (y / (float)HEIGHT) * 50);
//	printf("\n(%d;%d)\t%d\n\n", x, y, inf->color);
	return (0);
}

int					pull_ckey(int kc, int x, int y, void *param)
{
	t_inf			*inf;
	int				moreless;
	double			ratio;

	inf = (t_inf *)param;
	moreless = 0;
	ratio = (HEIGHT / (double)WIDTH) / 10;
	if (kc == 5 || kc == 4)
		moreless = (kc == 5) ? -1  : 1;

	printf("%f:1\n", ratio * 10);
	inf->ydlim = inf->xdlim + (ratio * moreless);
	inf->yulim = inf->xulim - (ratio * moreless);
	inf->xdlim = inf->ydlim + moreless / (float)10;
	inf->xulim = inf->yulim - moreless / (float)10;
	mandelbrot(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (x - x + y - y);
}
