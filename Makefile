NAME = so_long

HEADER = so_long.h

SRC =	main.c\
		utils_lib.c\
		map_check.c\
		get_next_line.c\
		get_next_line_utils.c\
		init.c\

MLX = ./mlx/libmlx.a

OBJ = ${SRC:.c=.o}

CC		= gcc

CFLAGS	= -Wall -Wextra -Werror

MFLAGS = -framework OpenGL -framework AppKit

RM		= rm -f

all:		${NAME}

${NAME}:	${LIBFT} ${MLX} ${OBJ} ${HEADER}
			${CC} ${cFLAGS} ${MFLAGS} ${OBJ} ${LIBFT} ${MLX} -o ${NAME}

${MLX}:		
			make -C ./mlx

%.o : %.c
			${CC} ${CFLAGS} -c $< -o $@

clean:	
			${RM} ${OBJ}
			make -C ./mlx clean

fclean:		clean
			${RM} ${NAME}
			make  -C ./mlx fclean

re:			fclean all

.PHONY:		all clean fclean re
