#include	"wolf.h"

static void	aff_the_sky(t_data *data)
{
  int		i;
  unsigned char	grad_g;
  unsigned char	grad_r;

  i = 0;
  grad_g = data->img->color_sky_2;
  grad_r = data->img->color_sky_3;
  while (i < (S_LINE * CENTER))
    {
      ADDR_FP[i] = data->img->color_sky_1;
      ADDR_FP[i + 1] = grad_g;
      ADDR_FP[i + 2] = grad_r;
      ADDR_FP[i + 3] = data->img->color_sky_4;
      i = i + 4;
      if (COLOR == 0)
	{
	  if (i % (S_LINE * 5) == 0)
	    {
	      if (grad_g - 1 >= 0)
		grad_g -= 1;
	      if (grad_r - 1 >= 0)
		grad_r -= 1;
	    }
	}
    }
}

static void	aff_the_ground(t_data *data)
{
  int		i;
  unsigned char	grad_g;

  i = (S_LINE * CENTER);
  grad_g = data->img->color_ground_2;
  while (i < (S_LINE * HEIGHT))
    {
      ADDR_FP[i] = data->img->color_ground_1;
      ADDR_FP[i + 1] = grad_g;
      ADDR_FP[i + 2] = data->img->color_ground_3;
      ADDR_FP[i + 3] = data->img->color_ground_4;
      i = i + 4;
      if (COLOR == 0)
	{
	  if (i % (S_LINE * 6) == 0)
	    grad_g += 1;
	}
    }
}

void            my_aff_font(t_data *data)
{
  aff_the_sky(data);
  aff_the_ground(data);
}
