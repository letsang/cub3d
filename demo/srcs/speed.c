#include	"wolf.h"

void		increase_speed(t_data *data)
{
  double	temp_speed;

  temp_speed = SPEED + 0.005;
  if (temp_speed < 0.40)
    SPEED = temp_speed;
}

void		decrease_speed(t_data *data)
{
  double	temp_speed;

  temp_speed = SPEED - 0.005;
  if (temp_speed > 0.02)
    SPEED = temp_speed;
}
