#include	<stdio.h>
#include	"wolf.h"

void		increase_FOV(t_data *data)
{
  double	temp_p;

  temp_p = SEG_P - 0.01;
  if (temp_p > 0.75)
    SEG_P = temp_p;
}

void		decrease_FOV(t_data *data)
{
  double	temp_p;

  temp_p = SEG_P + 0.01;
  if (temp_p < 1.5)
    SEG_P = temp_p;
}
