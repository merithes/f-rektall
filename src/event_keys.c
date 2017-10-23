#include "hfractol.h"

void			move(t_inf *inf, int kc)
{
	if (kc == 0)
		inf->xdlim -= (inf->xulim - inf->xdlim) / 20;
   	if (kc == 2)
		inf->xdlim += (inf->xulim - inf->xdlim) / 20;
	if (kc == 0)
		inf->xulim -= (inf->xulim - inf->xdlim) / 20;
   	if (kc == 2)
		inf->xulim += (inf->xulim - inf->xdlim) / 20;
	if (kc == 13)
		inf->ydlim -= (inf->yulim - inf->ydlim) / 20;
   	if (kc == 1)
		inf->ydlim += (inf->yulim - inf->ydlim) / 20;
	if (kc == 13)
		inf->yulim -= (inf->yulim - inf->ydlim) / 20;
   	if (kc == 1)
		inf->yulim += (inf->yulim - inf->ydlim) / 20;
}

void			keyset(t_inf *inf, int kc)
{
	int i;

	i = 0;
	if (kc == 0 || kc == 2 || kc == 1 || kc == 13)
		move(inf, kc);
	else if (kc == 15)
		inf->revert = inf->revert ? 0 : 1;
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
	ft_bzero(inf->img->str, inf->img->len * HEIGHT);
}

int					pull_event(int kc, void *param)
{
	t_inf			*inf;

	inf = (t_inf *)param;
	if (kc == 65307 || kc == 53)
		exits(1, inf);
	else
		keyset(inf, kc);
	return (0);
}
