# cub3d
compiler cub3d sous macos : gcc -I./mlx -L./mlx -lmlx -framework OpenGL -framework AppKit main.c
compiler cub3d sous linux : gcc main.c -I ./mlx -L ./mlx -lmlx -lXext -lX11 -lm
