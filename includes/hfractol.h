#ifndef HFRACTOL_H
# define HFRACTOL_H

# include <stdlib.h>
# include <unistd.h>
# include <math.h>
# include <string.h>
# include "mlx.h"
# include "libft.h"

/*
** WINDOW PROPERTIES
*/

# define WIDTH 600
# define HEIGHT 600
# define TITLE "Fractroll"

/*
** DEFINED VALUES
*/

# define X 0
# define Y 1

# define ZR 0
# define ZI 1
# define CR 2
# define CI 3

# define MLXID 0
# define WINID 1

# define MX_IT 50
# define DIFF_IT 3
# define DEF_COL 0x000101

# define DIFF_X (1/(float)10)
# define DIFF_Y (1/(float)10)

# define DIFF_MARG (1/(float)10)

/*
** MATH
*/

# define TRX(a, b) ((int)(((a - b.xdlim) / (b.xulim - b.xdlim)) * WIDTH))
# define TRY(a, b) ((int)(((a - b.ydlim) / (b.yulim - b.ydlim)) * HEIGHT))
# define PYTH(a, b) (sqrt(a * a + b * b))

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
	int					safe;
	int					color;
	t_img				*img;
	double				zoomey;
	int					revert;
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
int						pull_cursor(int x, int y, void *prm);
int						pull_ckey(int kc, int x, int y, void *prm);
void					keyset(t_inf *inf, int kc);

#endif
