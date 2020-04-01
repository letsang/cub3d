#include "wolf.h"
#include <stdio.h>

static void	aff_wall(t_data *data, unsigned char r, unsigned char g, unsigned char b)
{
  int		compt;
  int		top_rank_line;
  int		bot_rank_line;
  int		bot_limit;
  
  bot_limit = HEIGHT * S_LINE;
  for (compt = 0; compt <= S_WALL; compt++)
    {
      top_rank_line = LIN_C - compt * S_LINE;
      bot_rank_line = LIN_C + compt * S_LINE;
      
      if (top_rank_line >= 0)
	{
	  ADDR_FP[top_rank_line] = b;
	  ADDR_FP[top_rank_line + 1] = g;
	  ADDR_FP[top_rank_line + 2] = r;
	  ADDR_FP[top_rank_line + 3] = data->img->color_wall_4;
	}
      if (bot_rank_line <= bot_limit)
	{
	  ADDR_FP[bot_rank_line] = b;
	  ADDR_FP[bot_rank_line + 1] = g;
	  ADDR_FP[bot_rank_line + 2] = r;
	  ADDR_FP[bot_rank_line + 3] = data->img->color_wall_4;
	}
    }
}

void		my_aff_wall(t_data *data)
{
  int		tmp;
  unsigned char	r;
  unsigned char	g;
  unsigned char	b;
  
  if ((tmp = (int)data->img->color_wall_3 - (int)DIST_W) < 0) //La distance mur/player influe sur la couleur
    tmp = 0;
  r = (unsigned char)tmp;
  if ((tmp = (int)data->img->color_wall_2 - (int)DIST_W) < 0)
    tmp = 0;
  g = (unsigned char)tmp;
  if ((tmp = (int)data->img->color_wall_1 - (int)DIST_W) < 0)
    tmp = 0;
  b = (unsigned char)tmp;
  S_WALL = (int)(HEIGHT / (2 * DIST_W));
  LIN_C = (int)((CENTER * S_LINE) + (RNK_COL * BPP / 8));
  aff_wall(data, r, g, b);
}
