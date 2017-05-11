/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vboivin <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/11 14:20:37 by vboivin           #+#    #+#             */
/*   Updated: 2017/05/11 19:37:15 by vboivin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hfractol.h"

void				frac(void *p[2])
{
	float x;
	float y;
	int maxIterations = 50; // increasing this will give you a more detailed fractal

	complex double Z;
	complex double C;
	int iterations;
	for(x=-2; x<=2; x+= (float)(4/(float)WIDTH))
	{
		for(y=-2; y<=2; y+= (float)(4/(float)HEIGHT))
		{
			iterations = 0;
			C = CMPLX(x, y);
			Z = 0;
			while(cabs(Z) < 2 && iterations < maxIterations)
			{
				Z = Z*Z + C;
				iterations++;
			}
			printf("printing:(%d;%d)::%d\n", (int)(((x/4) * WIDTH) + WIDTH/2), (int)(((y/4) * HEIGHT) + HEIGHT/2), iterations);
			if (iterations > 0)
				mlx_pixel_put(p[MLXID], p[WINID], (int)(((x / 4) * WIDTH) + (WIDTH /2)), (int)(((y / 4) * HEIGHT) + (HEIGHT/2)), 0x010001 * iterations + (int)(((double)1/(double)iterations * 2) * 0X040001));
			usleep(1);
		}
	}
}

int					main(void)
{
	void			*p[2];

	p[MLXID] = mlx_init();
	p[WINID] = mlx_new_window(p[MLXID], WIDTH, HEIGHT, TITLE);
	frac(p);
	mlx_loop(p[MLXID]);
}
