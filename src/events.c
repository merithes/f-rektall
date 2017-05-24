#include "hfractol.h"

void			keyset(t_inf *inf, int kc)
{
	int i;
	printf("%d\n", kc);

	i = 0;
	if (kc == 65365 || kc == 65366)
		inf->def += (kc == 65365) ? DIFF_IT : -DIFF_IT;
	else if (kc == 113 || kc == 100)
		inf->xulim += (kc == 113) ? DIFF_Y : -DIFF_Y;
	else if (kc == 42 && ++i)
		ft_bzero(inf->img->str, inf->img->len * HEIGHT);
	inf->def = (inf->def < 0) ? 0 : inf->def;
	if (!i)
		mandelbrot(*inf);
}

int					pull_event(int kc, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	if (kc == 65307)
		exits(1, inf);
	else
		keyset(inf, kc);
//	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (0);
}
