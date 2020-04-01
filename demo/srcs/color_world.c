#include	"wolf.h"

void		classic_colors(t_data *data)
{
  data->img->color_sky_1 = 246; /*246 BLUE*/
  data->img->color_sky_2 = 214; /*214 GREEN */
  data->img->color_sky_3 = 128; /*128 RED*/
  data->img->color_sky_4 = 0; /*183*/
  data->img->color_ground_1 = 0;
  data->img->color_ground_2 = 80; /*80 -  */
  data->img->color_ground_3 = 0;
  data->img->color_ground_4 = 0;
  data->img->color_wall_1 = 142;
  data->img->color_wall_2 = 196;
  data->img->color_wall_3 = 229;
  data->img->color_wall_4 = 110;
  BLIND = 0;
}

void		color_two(t_data *data)
{
  data->img->color_sky_1 = 50;
  data->img->color_sky_2 = 8;
  data->img->color_sky_3 = 0;
  data->img->color_sky_4 = 0;
  data->img->color_ground_1 = 30;
  data->img->color_ground_2 = 30;
  data->img->color_ground_3 = 30;
  data->img->color_ground_4 = 0;
  data->img->color_wall_1 = 10;
  data->img->color_wall_2 = 10;
  data->img->color_wall_3 = 10;
  data->img->color_wall_4 = 10;
}

void		x_ray_charles(t_data *data)
{
  BLIND++;
  if (BLIND == 1)
    {
      data->img->color_sky_1 = 0;
      data->img->color_sky_2 = 0;
      data->img->color_sky_3 = 0;
      data->img->color_sky_4 = 0;
      data->img->color_ground_1 = 0;
      data->img->color_ground_2 = 0;
      data->img->color_ground_3 = 0;
      data->img->color_ground_4 = 0;
      data->img->color_wall_1 = 7;
      data->img->color_wall_2 = 7;
      data->img->color_wall_3 = 7;
      data->img->color_wall_4 = 7;
      COLOR = 0;
    }
  else
    {
      BLIND = 0;
      COLOR = 0;
      classic_colors(data);
    }
}
