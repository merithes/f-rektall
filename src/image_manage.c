#include "hfractol.h"

void				create_image(t_inf *inf)
{
	t_img			*img;

	if(!(img = malloc(S_IMG)))
		exits(2, inf);
	img->pid = mlx_new_image(inf->mid, WIDTH, HEIGHT);
	img->str = mlx_get_data_addr(img->pid, &img->bpp, &img->len, &img->end);
	inf->img = img;
}

void				set_pixie(t_inf *inf, int x, int y, unsigned int color)
{
	char			RGB[3];
	char			*to_manip;
	int				i;
	int				len;

	i = 0;
	len = inf->img->len / (inf->img->bpp / 8);
	to_manip = inf->img->str;
	while (i <= 3)
	{
		RGB[i++] = color % 256;
		color /= 256;
	}
	i = (y * len) + x;
	if(!inf->img->end)
	{
		i *= (inf->img->bpp / 8);
		to_manip[i + 0] = RGB[0];
		to_manip[i + 1] = RGB[1];
		to_manip[i + 2] = RGB[2];
	}
	else
	{
		i *= (inf->img->bpp / 8);
		to_manip[i + 0] = RGB[2];
		to_manip[i + 1] = RGB[1];
		to_manip[i + 2] = RGB[0];
	}
}
