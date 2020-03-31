#include "cub3d.h"

void	fill_image(t_data *data, int x,	int y, int color)
{
	char		*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

void	draw_square(t_data *data, int x, int y,	int color)
{
	int i, j = 0;
	while (j < y)
	{
		while (i < x)
		{
			fill_image(data, i, j, color);
			i++;
		}
		i = 0;
		j++;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

void	draw_circle(t_data *data, int x, int y, int r, int color)
{
	double i, angle, x1, y1;

	i = 0;
	while (r > 0)
	{
		while (i < 360)
		{
			angle = i;
			x1 = r * cos(angle * PI / 180);
			y1 = r * sin(angle * PI	/ 180);
			fill_image(data, x + x1, y + y1, color);
			i += 0.1;
		}
		i = 0;
		r--;
	}
	mlx_put_image_to_window(data->mlx_ptr, data->mlx_win, data->img, 0, 0);
}

int	press_key(int key, t_data *data)
{
	if (key == Z)
		draw_circle(data, 100, 100, 80, BLUE);
	if (key == S)
		draw_square(data, 100, 100, RED);
	if (key == Q)
		draw_square(data, 150, 150, GREEN);
	if (key == D)
		draw_circle(data, 100, 100, 50, YELLOW);
	if (key == ESC)
		exit(1);
	return (0);
}

int	main(void)
{
	t_data data;
/*** SET MLX PTR ***/
	if ((data.mlx_ptr = mlx_init()) == NULL)
		return (EXIT_FAILURE);
	if ((data.mlx_win = mlx_new_window(data.mlx_ptr, WIDTH, HEIGHT, "Hello, World!")) == NULL)
		return (EXIT_FAILURE);
/*** SET IMAGE PTR ***/
	if ((data.img =	mlx_new_image(data.mlx_ptr, WIDTH, HEIGHT)) == NULL)
		return (EXIT_FAILURE);
/*** GET THE IMAGE ADDRESS PTR ***/
	data.addr = mlx_get_data_addr(data.img,	&data.bits_per_pixel, &data.line_length, &data.endian);
/*** PUT PIXELS IN THE IMAGE ADDRESS PTR ***/
	mlx_hook(data.mlx_win, KeyPress, KeyPressMask, &press_key, &data);
/*** LOOP TO MAINTAIN WINDOW ***/
	mlx_loop(data.mlx_ptr);
	return (EXIT_SUCCESS);
}
