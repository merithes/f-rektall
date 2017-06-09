#include "hfractol.h"

void			keyset(t_inf *inf, int kc)
{
	int i;

	i = 0;	
	if (kc == 0 || kc == 2)
	{
		inf->xdlim += (kc == 0) ? -0.1 : 0.1;
		inf->xulim += (kc == 0) ? -0.1 : 0.1;
	}
	else if (kc == 1 || kc == 13)
	{
		inf->ydlim += (kc == 13) ? -0.1 : 0.1;
		inf->yulim += (kc == 13) ? -0.1 : 0.1;
	}
	else if (kc == 65365 || kc == 65366 || kc == 116 || kc == 121)
		inf->def += (kc == 65366 || kc == 116) ? DIFF_IT : -DIFF_IT;
	else if (kc == 42 && ++i)
		ft_bzero(inf->img->str, inf->img->len * HEIGHT);
	else if (kc != -1)
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
	inf->color = (int)((x / (float)WIDTH) * 2) * 0x010000;
	inf->color += (int)((y / (float)HEIGHT) * 2) * 0x000100;
	keyset(inf, -1);
	printf("\t%d\t", x);
	printf("%d\n", y);
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
	ratio = (HEIGHT / (double)WIDTH);
	if (kc == 5 || kc == 4)
		moreless = (kc == 5) ? -1  : 1;

//	printf("b:%d\tfor(%d;%d)\n", kc, x, y);
	inf->ydlim *= 1 - (moreless /(double)10) * ratio;
	inf->yulim *= 1 - (moreless /(double)10) * ratio;
	inf->xdlim *= 1 - (moreless /(double)10);
	inf->xulim *= 1 - (moreless /(double)10);
	mandelbrot(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (x - x + y - y);
}
