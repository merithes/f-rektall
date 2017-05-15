#ifndef HFRACTOL_H
# define HFRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include <complex.h>
# include "mlx.h"
# include "libft.h"

/*
** WINDOW PROPERTIES
*/

# define WIDTH 800
# define HEIGHT 600
# define TITLE "Fractroll"

/*
** DEFINED VALUES
*/

# define X 0
# define Y 1

# define MLXID 0
# define WINID 1

# define MX_IT 30
# define DIFF_IT 1

# define DIFF_X (1/(float)100)
# define DIFF_Y (1/(float)100)

/*
** MATH
*/

# define TRX(a) ((int)(((a / 2) * WIDTH )))
# define TRY(a) ((int)(((a / 2) * HEIGHT)))

/*
** OTHERS
*/

# define S_INF (sizeof(t_inf))
# define S_IMG (sizeof(t_img))

/*
** FABULOUS AND AMAZING STRUCTURES
*/

typedef struct			s_img
{
	void				*pid;
	char				*str;
	int					end;
	int					bpp;
	int					len;
}						t_img;

typedef struct			s_inf
{
	void				*wid;
	void				*mid;
	int					def;
	t_img				*img;
	double				xdlim;
	double				xulim;
	double				ydlim;
	double				yulim;
}						t_inf;

/*
** DECLARATIONS
*/

void					exits(int errno, t_inf *inf);
void					create_image(t_inf *inf);
void					set_pixie(t_inf *inf, int x, int y, unsigned int color);
void					mandelbrot(t_inf inf);
int						pull_event(int kc, void *prm);
void					keyset(t_inf *inf, int kc);

#endif
