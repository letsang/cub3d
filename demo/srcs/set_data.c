#include	"wolf.h"

static void	set_map(t_data *data, int set_lin, int set_col)
{
  static int	map[11][24] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
  };

  while (set_lin < 11)
    {
      while (set_col < 24)
        {
          data->mov->map[set_lin][set_col] = map[set_lin][set_col];
          set_col++;
        }
      set_col = 0;
      set_lin++;
    }
}

void		set_game(t_data *data)
{
  POS_X = 2;
  POS_Y = 2;
  ANGLE = 0;
  COS_ANGLE = 1; //cos((ANGLE / 180) * P) == cos(0) == 1
  SIN_ANGLE = 0; //sin((ANGLE / 180) * P) == sin(0) == 0
  SPEED = 0.15;
  SEG_P = 1.0;
  CENTER = (HEIGHT / 2);
  DIST_W = 0;
  data->mov->press_z = '0';
  data->mov->press_s = '0';
  data->mov->press_q = '0';
  data->mov->press_d = '0';
  data->mov->press_up = '0';
  data->mov->press_down = '0';
  data->mov->press_left = '0';
  data->mov->press_right = '0';
  data->mov->press_inc_speed = '0';
  data->mov->press_dec_speed = '0';
  data->rayc->var_seg_p1 = '0';
  data->rayc->var_seg_p2 = '0';
  COLOR = 0;
  BLIND = 0;
  classic_colors(data);
}

void		set_data(t_image *img, t_move *mov, t_rayc *rayc, t_data *data)
{
  data->img = img;
  data->mov = mov;
  data->rayc = rayc;
  set_game(data);
  set_map(data, 0, 0);
}
