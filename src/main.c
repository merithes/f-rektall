#include "hfractol.h"

void				exits(int errno, t_inf *inf)
{
	if (inf)
	{
		mlx_destroy_window(inf->mid, inf->wid);
		if (inf->img)
			if (inf->img->pid)
				mlx_destroy_image(inf->mid, inf->img->pid);
		if (inf->img)
			free(inf->img);
		free(inf);
	}
	if (errno == 1)
		ft_putstr("exiting.\n");
	if (errno == 2)
		ft_putstr("couldn't allocate memory.\n");
	exit(errno);
}

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
	create_image(outp);
	return (outp);
}

int					main(void)
{
	t_inf			*inf;
	if (!(inf = set_inf()))
		return (0);
	mandelbrot(*inf);
	mlx_put_image_to_window(inf->mid, inf->wid, inf->img->pid, 0, 0);
	mlx_hook(inf->wid, 2, 3, pull_event, inf);
	mlx_mouse_hook(inf->wid, pull_ckey, inf);
	mlx_hook(inf->wid, 6, (1L << 6), pull_cursor, inf);
	mlx_loop(inf->mid);
	return (0);
}
