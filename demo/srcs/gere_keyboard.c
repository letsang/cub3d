#include	<stdlib.h>
#include	"wolf.h"

int		press_key(int key_c, t_data *data)
{
  /*move_position*/
  if (key_c == Z)
    data->mov->press_z = '1';
  if (key_c == S)
    data->mov->press_s = '1';
  if (key_c == Q)
    data->mov->press_q = '1';
  if (key_c == D)
    data->mov->press_d = '1';
  /*move cam*/
  if (key_c == UP)
    data->mov->press_up = '1';
  if (key_c == DOWN)
    data->mov->press_down = '1';
  if (key_c == LEFT)
    data->mov->press_left = '1';
  if (key_c == RIGHT)
    data->mov->press_right = '1';
  /*change FOV*/
  if (key_c == VAR_P1)
    data->rayc->var_seg_p1 = '1';
  if (key_c == VAR_P2)
    data->rayc->var_seg_p2 = '1';
  /*change speed*/
  if (key_c == INC_SPEED )
    data->mov->press_inc_speed = '1';
  if (key_c == DEC_SPEED )
    data->mov->press_dec_speed = '1';
  return (0);
}

int		release_key(int key_c, t_data *data)
{
  /*move_position*/
  if (key_c == Z)
    data->mov->press_z = '0';
  if (key_c == S)
    data->mov->press_s = '0';
  if (key_c == Q)
    data->mov->press_q = '0';
  if (key_c == D)
    data->mov->press_d = '0';
  /*move cam*/
  if (key_c == UP)
    data->mov->press_up = '0';
  if (key_c == DOWN)
    data->mov->press_down = '0';
  if (key_c == LEFT)
    data->mov->press_left = '0';
  if (key_c == RIGHT)
    data->mov->press_right = '0';
  /*change FOV*/
  if (key_c == VAR_P1)
    data->rayc->var_seg_p1 = '0';
  if (key_c == VAR_P2)
    data->rayc->var_seg_p2 = '0';
  /*change speed*/
  if (key_c == INC_SPEED )
    data->mov->press_inc_speed = '0';
  if (key_c == DEC_SPEED )
    data->mov->press_dec_speed = '0';
  /*exit game*/
  if (key_c == ESCAPE)
    exit(1);
  /*reset game*/
  if (key_c == R)
    set_game(data);
  /*change colors*/
  if (key_c == TAB)
    switch_colors(data);
  if (key_c == B)
    x_ray_charles(data);
  return (0);
}

int		gere_keycode(t_data *data)
{
  if (data->mov->press_z == '1')
    move_up(data);
  if (data->mov->press_s == '1')
    move_down(data);
  if (data->mov->press_q == '1')
    move_left(data);
  if (data->mov->press_d == '1')
    move_right(data);
  if (data->mov->press_up == '1')
    look_up(data);
  if (data->mov->press_down == '1')
    look_down(data);
  if (data->mov->press_left == '1')
    turn_left(data);
  if (data->mov->press_right == '1')
    turn_right(data);
  if (data->rayc->var_seg_p1 == '1')
    decrease_FOV(data);
  if (data->rayc->var_seg_p2 == '1')
    increase_FOV(data);
  if (data->mov->press_inc_speed == '1')
    increase_speed(data);
  if (data->mov->press_dec_speed == '1')
    decrease_speed(data);
  my_raycasting(data);
  return (0);
}

void		switch_colors(t_data *data)
{
  COLOR++;
  if (COLOR == 2)
    {
      COLOR = 0;
      BLIND = 0;
    }
  if (COLOR == 0)
    classic_colors(data);
  if (COLOR == 1)
    color_two(data);
}
