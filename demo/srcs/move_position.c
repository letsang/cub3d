#include	<math.h>
#include	"wolf.h"

void		move_up(t_data *data)
{
  double	next_x;
  double	next_y;

  next_x = POS_X + (SPEED * COS_ANGLE);
  next_y = POS_Y + (SPEED * SIN_ANGLE);
  if (MAP[(int)next_x][(int)next_y] == 0)
    {
      POS_X = next_x;
      POS_Y = next_y;
    }
  else if (MAP[(int)next_x][(int)POS_Y] == 0) // Glissement contre les murs
    POS_X = next_x;
  else if (MAP[(int)POS_X][(int)next_y] == 0) // en X, ne changer que le Y et vice versa
    POS_Y = next_y;
}

void		move_down(t_data *data)
{
  double	next_x;
  double	next_y;

  next_x = POS_X - ((SPEED / 2) * COS_ANGLE);
  next_y = POS_Y - ((SPEED / 2) * SIN_ANGLE);
  if (MAP[(int)next_x][(int)next_y] == 0)
    {
      POS_X = next_x;
      POS_Y = next_y;
    }
  else if (MAP[(int)next_x][(int)POS_Y] == 0)
    POS_X = next_x;
  else if (MAP[(int)POS_X][(int)next_y] == 0)
    POS_Y = next_y;
}

void		move_left(t_data *data)
{
  double	angle;
  double	speed;
  double	next_x;
  double	next_y;

  angle = ANGLE + 90;
  if (angle > 360)
    angle -= 360;
  speed = SPEED / 2;
  next_x = POS_X + (speed * cos((angle / 180) * P));
  next_y = POS_Y + (speed * sin((angle / 180) * P));
  if (MAP[(int)next_x][(int)next_y] == 0)
    {
      POS_X = next_x;
      POS_Y = next_y;
    }
}

void		move_right(t_data *data)
{
  double	angle;
  double	speed;
  double	next_x;
  double	next_y;

  angle = ANGLE - 90;
  if (angle < 0)
    angle += 360;
  speed = SPEED / 2;
  next_x = POS_X + (speed * cos((angle / 180) * P));
  next_y = POS_Y + (speed * sin((angle / 180) * P));
  if (MAP[(int)next_x][(int)next_y] == 0)
    {
      POS_X = next_x;
      POS_Y = next_y;
    }
}
