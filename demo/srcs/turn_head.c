#include	<math.h>
#include	"wolf.h"

void		look_up(t_data *data)
{
  if (CENTER + (HEIGHT / 70) < HEIGHT)
    CENTER += (HEIGHT / 70);
}

void		look_down(t_data *data)
{
  if (CENTER - (HEIGHT / 70) > 0)
    CENTER -= (HEIGHT / 70);
}

void		turn_left(t_data *data)
{
  ANGLE += 4;
  if (ANGLE >= 360)
    ANGLE -= 360;
  COS_ANGLE = cos((ANGLE / 180) * P);
  SIN_ANGLE = sin((ANGLE / 180) * P);
}

void		turn_right(t_data *data)
{
  ANGLE -= 4;
  if (ANGLE < 0)
    ANGLE += 360;
  COS_ANGLE = cos((ANGLE / 180) * P);
  SIN_ANGLE = sin((ANGLE / 180) * P);
}
