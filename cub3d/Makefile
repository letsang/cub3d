NAME	= cub3d

SRC	= main.c

OBJS	= ${SRC:.c=.o}

CC	= gcc

RM	= rm -f

CFLAGS	= -Wall -Wextra -Werror -I./mlx

LDFLAGS	= -lmlx -lXext -lX11 -lm

all:	cub3d.h ${NAME}

${NAME}:${OBJS}
	gcc -o ${NAME} ${CFLAGS} ${OBJS} ${LDFLAGS}

clean:		
	${RM} ${OBJS}

fclean:	clean
	${RM} ${NAME}

re:	fclean all

.PHONY:	all clean fclean re
