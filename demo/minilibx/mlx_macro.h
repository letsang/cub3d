/*
** mlx_macro.h for minilibx in /home/brugue_m/rendu/MUL_2014_wolf3d/minilibx
** 
** Made by Maxime Bruguet
** Login   <brugue_m@epitech.net>
** 
** Started on  Tue Dec  2 13:43:47 2014 Maxime Bruguet
** Last update Sun Dec 21 22:13:44 2014 Maxime
*/

#ifndef MLX_MACRO_H_
# define MLX_MACRO_H_

/*
** Include
*/

#include <stdlib.h>
#include <math.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "mlx.h"

/*
** Maths macro
*/

# define DtR(a) (a * M_PI / 180)
# define RtD(a) (a * 180 / M_PI)
# define ABS(x) (x >= 0 ? (-x) : (x))
# define DIST_PROJ (WIDTH / 2) / tan(FOV / 2)
# define ANG_R FOV / WIDTH

/*
** Window parameter / Color
*/

# define WIDTH 1200
# define HEIGHT 800
# define SKY 0x01B0F0
# define GROUND 0x96CA2D
# define WALL 0x7F8283
# define P 1
# define D_ P / 2
# define FOV 60

/*
** Key code
*/

# define ESC 65307
# define RIGHT 65363
# define LEFT 65361
# define UP 65362
# define DOWN 65364
# define PAGEUP 65365
# define PAGEDOWN 65366
# define END 65367
# define Z 122
# define S 115
# define Q 113
# define D 100

/*
** Boolean
*/

# define TRUE 0
# define FALSE 1

/*
** structure MLX
*/

typedef struct	s_mlx
{
  void		*mlx_ptr;
  void		*win_ptr;
  void		*img_ptr;
  char		*data;
  int		bpp;
  int		sizeline;
  int		endian;
  int		lim1;
  int		lim2;
  int		wall;
  int		ground;
  int		sky;
}		t_mlx;

typedef struct	s_coord
{
  int		x0;
  int		y0;
  double	ang_b;
  int		map[6][6];
}		t_crd;

typedef struct	s_vector
{
  double	Vx;
  double	Vy;
  double	ang;
}		t_vec;

/*
** Initialization Structure et Check pointer mlx
*/

void		init_struct(t_mlx *, t_crd *);

/*
** Gere function for mlx_loop
*/

int		gere_mouse(int, int, int, t_mlx *);
int		gere_key(int, t_mlx *);
int		gere_expose(t_mlx *);

/*
** Display
*/

void		my_pixel_put_to_image(int, int, int, t_mlx *);
void		ground_sky(t_mlx *, int, int);
void		wall(t_mlx *, int, int);
void		my_putstr(char *);

/*
** Calc function
*/

int		get_k(t_vec *, t_crd *);
int		get_k_ver(t_vec *, t_crd *);
int		get_k_hor(t_vec *, t_crd *);
int		get_k_loop(t_vec *, t_crd *);
t_vec		*vect_dir(t_crd *, t_vec *, int);

/*
** Creat S_map
*/

void		s_map(t_crd *);

#endif
