NAME = so_long

HEADER = so_long.h

SRC =	main.c\
		map_check_adds.c\
		map_check.c\
		init.c\
		enemy.c \
		
LIBFT = ./libft/libft.a

LIB_BINARY = -L ./libft -lft 

MLX = ./mlx/libmlx.a

OBJ = ${SRC:.c=.o}

CC		= gcc

# CFLAGS	= -Wall -Wextra -Werror

MFLAGS = -framework OpenGL -framework AppKit

RM		= rm -f

all:		${NAME}

${NAME}:	${LIBFT} ${MLX} ${OBJ} ${HEADER}
			${CC} ${CFLAGS} ${MFLAGS} ${OBJ} ${MLX} $(LIB_BINARY) -o $(NAME)

$(LIBFT):
		make -C ./libft/

${MLX}:		
			make -C ./mlx

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:	
			${RM} ${OBJ}
			make -C ./mlx clean
			make -C ./libft/ clean

fclean:		clean
			${RM} ${NAME}
			make  -C ./mlx clean
			make -C ./libft/ fclean

re:			fclean all

.PHONY:		all clean fclean re
