#include "hfractol.h"

void			keyset(t_inf *inf, int kc)
{
	if (kc == 65362 || kc == 65364)
		inf->def += (kc == 65362) ? DIFF_IT : -DIFF_IT;
	inf->def = (inf->def < 0) ? 0 : inf->def;
	mandelbrot(*inf);
}

int					pull_event(int kc, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	printf("%d\n", kc);
	if (kc == 65307)
		exits(1, inf);
	else
		keyset(inf, kc);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	return (0);
}
