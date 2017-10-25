/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 09:47:21 by vboivin           #+#    #+#             */
/*   Updated: 2017/10/25 10:18:59 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int					main(int ac, char *av[])
{
	t_inf			*inf;

	if (!(inf = fractal_initiate(ac, av)))
		return (0);
	mlx_hook(inf->wid, 2, 3, pull_event, inf);
	mlx_mouse_hook(inf->wid, pull_ckey, inf);
	mlx_hook(inf->wid, 6, (1L << 6), pull_cursor, inf);
	mlx_expose_hook(inf->wid, call_fractal, inf);
	mlx_loop(inf->mid);
	return (0);
}
