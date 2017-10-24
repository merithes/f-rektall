/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:51:38 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/24 21:20:05 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	outp->ji = 1;
	outp->jr = -1;
	outp->revert = 0;
	create_image(outp);
	return (outp);
}

t_inf				*fractal_initiate(int ac, char *av[])
{
	t_inf			*outp;

	if (ac == 1 || ac > 2)
	{
		pcat(NARG, DARG, NULL, 0);
		return NULL;
	}
	printf("truc\n");
	if (!(outp = set_inf()))
		return (NULL);
	if (!ft_strcmp("mandelbrot", av[1]))
		outp->fractal = MANDL;
	else if (!ft_strcmp("julia", av[1]))
		outp->fractal = JULIA;
	else if (!ft_strcmp("bship", av[1]))
		outp->fractal = BSHIP;
	outp->switcher = 1;
	call_fractal(outp);
	return outp;
}
