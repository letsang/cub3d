NAME		=	wolf3D

CC		=	gcc

RM		=	rm -f

COMPILEFLAGS	+=	-Wall -Wextra -fPIC

INCLUDES	=	-I ./includes -I./minilibx

LDFLAGS		=	-L ./minilibx -lmlx -lXext -lX11 -lm

CFLAGS		=	$(COMPILEFLAGS) $(INCLUDES)

SRCPATH		=	srcs

SRCS		=	$(SRCPATH)/main.c		\
			$(SRCPATH)/set_data.c           \
			$(SRCPATH)/gere_keyboard.c      \
			$(SRCPATH)/move_position.c      \
			$(SRCPATH)/turn_head.c          \
			$(SRCPATH)/raycasting.c         \
			$(SRCPATH)/aff_font.c           \
			$(SRCPATH)/aff_wall.c           \
			$(SRCPATH)/color_world.c        \
			$(SRCPATH)/fov.c		\
			$(SRCPATH)/speed.c

OBJS		=	$(SRCS:.c=.o)

DEBUG		=	no

ifeq ($(DEBUG), yes)
CC		=	clang
COMPILEFLAGS	=	-Weverything -Wno-padded #voir Data Structure Alignment
LDFLAGS		+=	-g
endif

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) -o $(NAME) $(CFLAGS) $(OBJS) $(LDFLAGS)

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all
