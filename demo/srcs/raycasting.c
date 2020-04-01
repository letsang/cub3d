#include	<math.h>
#include	"wolf.h"

void		my_raycasting(t_data *data)
{
  int		line;
  int		column;
  
  RNK_COL = 0;
  my_aff_font(data);
  while (RNK_COL < WIDTH)
  {
	  Y1 = SEG_P * ((WIDTH / 2) - RNK_COL) / WIDTH;
	  VECT_X = 0.5 * COS_ANGLE - Y1 * SIN_ANGLE;
	  VECT_Y = 0.5 * SIN_ANGLE + Y1 * COS_ANGLE;
	  DIST_W = 1;
	  do
	  {
		  line = (int)(POS_X + (DIST_W * VECT_X));
		  column = (int)(POS_Y + (DIST_W * VECT_Y));
		  DIST_W += 0.005; // Précision de l'aliasing/crénelage
	  } while (data->mov->map[line][column] == 0 && DIST_W < 100);
	  my_aff_wall(data);
	  RNK_COL++;
  }
  mlx_put_image_to_window(data->img->mlx_p, data->img->win_p, data->img->img_p, 0, 0);
}
