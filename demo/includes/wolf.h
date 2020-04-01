#ifndef		WOLF_H_
# define	WOLF_H_

#include	"mlx.h"

# define	WIDTH	640 // Largeur écran
# define	HEIGHT	400 // Hauteur écran

# define	P	3.141592653589793 // Pi lel

// Valeurs correspondant au touches clavier
# define	ESCAPE	65307
# define	Z	122
# define	Q	113
# define	S	115
# define	D	100
# define	UP	65362
# define	LEFT	65361
# define	DOWN	65364
# define	RIGHT	65363
# define	R	114
# define	TAB	65289
# define	B	98
# define	VAR_P1	111
# define	VAR_P2	112
# define	INC_SPEED 65365
# define	DEC_SPEED 65366
# define	SHIFT	65505

# define	COLOR	data->img->color
# define	BLIND	data->img->blind // Booléen (0: Normal, 1: Blind mode)
# define	ADDR_FP	data->img->data
# define	BPP	data->img->bpp // (bits_per_pixel)
# define	S_LINE	data->img->size_l // (size_line)
# define	CENTER	data->img->axis
# define	LIN_C	data->img->lin_c
# define	S_WALL	data->img->size_wall

# define	MAP	data->mov->map
# define	POS_X	data->mov->pos_x // Coordonnée X position Joueur
# define	POS_Y	data->mov->pos_y // Coordonnée Y position Joueur
# define	ANGLE	data->mov->angle
# define	SPEED	data->mov->speed
# define	COS_ANGLE	data->mov->cos_angle
# define	SIN_ANGLE	data->mov->sin_angle

# define	DIST_W	data->rayc->distance
# define	SEG_P	data->rayc->seg_projec // (varier pour modifier le FOV)
# define	DIST_P	data->rayc->dist_p
# define	Y1	data->rayc->x1
# define	X1	data->rayc->y1
# define	VECT_X	data->rayc->vect_dir_x
# define	VECT_Y	data->rayc->vect_dir_y
# define	X_REAL	data->rayc->x_real
# define	Y_REAL	data->rayc->y_real
# define	RNK_COL	data->rayc->compt_col // Rang de la colonne de l'écran (min= 0, max= WIDTH)

typedef	struct		s_image
{
  void			*mlx_p;
  void			*win_p;
  void			*img_p;
  unsigned char		*data;
  int			bpp;
  int			size_l;
  int			endn; // (endian)
  int			axis;
  int			lin_c;
  int			size_wall;
  int			blind;
  unsigned char		color;
  unsigned char		color_sky_1;
  unsigned char		color_sky_2;
  unsigned char		color_sky_3;
  unsigned char		color_sky_4;
  unsigned char		color_ground_1;
  unsigned char		color_ground_2;
  unsigned char		color_ground_3;
  unsigned char		color_ground_4;
  unsigned char		color_wall_1;
  unsigned char		color_wall_2;
  unsigned char		color_wall_3;
  unsigned char		color_wall_4;
}			t_image;

typedef	struct		s_move
{
  int			map[11][24];
  double		pos_x;
  double		pos_y;
  double		angle;
  double		cos_angle;
  double		sin_angle;
  double		speed;
  char			press_z; // avancer
  char			press_s; // reculer
  char			press_q; // aller à gauche
  char			press_d; // aller à droite
  char			press_up; // regarder en haut
  char			press_down; // regarder en bas
  char			press_left; // se tourner vers la gauche
  char			press_right; // se tourner vers la droite
  char			press_inc_speed; // increase speed
  char			press_dec_speed; // decrease speed
}			t_move;

typedef	struct		s_rayc
{
  double		distance;
  double		prev_distance;
  double		seg_projec;
  double		dist_p;
  double		x1;
  double		y1;
  double		vect_dir_x;
  double		vect_dir_y;
  double		x_real;
  double		y_real;
  double		compt_col;
  char			var_seg_p1;
  char			var_seg_p2;
}			t_rayc;

typedef	struct		s_data
{
  struct s_image	*img;
  struct s_move		*mov;
  struct s_rayc		*rayc;
}			t_data;

void			set_data(t_image *, t_move *, t_rayc *, t_data *);
void			set_game(t_data *);
int			gere_keycode(t_data *);
int			press_key(int, t_data *);
int			release_key(int, t_data *);
void			keycode_move_position(int, t_data *);
void			keycode_turn_head(int, t_data *);
void			move_up(t_data *);
void			move_down(t_data *);
void			move_left(t_data *);
void			move_right(t_data *);
void			look_up(t_data *);
void			look_down(t_data *);
void			turn_left(t_data *);
void			turn_right(t_data *);
void			gere_speed(int, t_data *);
void			switch_colors(t_data *);
void			classic_colors(t_data *);
void			color_two(t_data *);
void			x_ray_charles(t_data *);
void			my_raycasting(t_data *);
void			my_aff_font(t_data *);
void			my_aff_wall(t_data *);
void			increase_FOV(t_data *);
void			decrease_FOV(t_data *);
void			increase_speed(t_data *);
void			decrease_speed(t_data *);

#endif			/*WOLF_H_*/
