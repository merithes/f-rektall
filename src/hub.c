/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hub.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 17:51:38 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 10:13:38 by vboivin          ###   ########.fr       */
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
	outp->lock = 0;
	outp->switcher = 1;
	outp->fractal = 0;
	create_image(outp);
	return (outp);
}

int					check_inp(char *av)
{
	if (!av)
		return (-1);
	if (!ft_strcmp("mandelbrot", av))
		return (0);
	else if (!ft_strcmp("julia", av))
		return (0);
	else if (!ft_strcmp("batman", av))
		return (0);
	else if (!ft_strcmp("moth", av))
		return (0);
	else if (!ft_strcmp("devil", av))
		return (0);
	else if (!ft_strcmp("bship", av))
		return (0);
	else if (!ft_strcmp("rising_bug", av))
		return (0);
	else if (!ft_strcmp("ray_manta", av))
		return (0);
	else
		return (-1);
}

t_inf				*fractal_initiate(int ac, char *av[])
{
	t_inf			*outp;

	if (ac == 1 || ac > 2 || 0 > check_inp(av[1]))
		pcat(DARGO, DARGS, (char *)(outp = (t_inf *)NULL), 0);
	if ((0 > check_inp(av[1])) || !(outp = set_inf()))
		return (NULL);
	if (!ft_strcmp("mandelbrot", av[1]))
		outp->fractal = MANDL;
	else if (!ft_strcmp("julia", av[1]))
		outp->fractal = JULIA;
	else if (!ft_strcmp("batman", av[1]))
		outp->fractal = BATMN;
	else if (!ft_strcmp("moth", av[1]))
		outp->fractal = MOTHH;
	else if (!ft_strcmp("devil", av[1]))
		outp->fractal = DEVIL;
	else if (!ft_strcmp("bship", av[1]))
		outp->fractal = BSHIP;
	else if (!ft_strcmp("rising_bug", av[1]))
		outp->fractal = RIBUG;
	else if (!ft_strcmp("ray_manta", av[1]))
		outp->fractal = RAYMN;
	call_fractal(outp);
	return (outp);
}
