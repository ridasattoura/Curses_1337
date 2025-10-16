NAME = so_long
NAMEBONUS = so_long_bonus
SRC = 	Mandatory/flood_fill.c Mandatory/ft_check_extension_main.c Mandatory/ft_check_wall.c Mandatory/ft_function_key.c Mandatory/ft_put_image_to_window.c Mandatory/main.c \
		Mandatory/ft_check_extension.c Mandatory/ft_check_moves.c  Mandatory/ft_error.c Mandatory/ft_load_images.c Mandatory/ft_steps_x_y.c 
GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c
BNS = 	Bonus/flood_fill_bonus.c Bonus/ft_check_extension_main_bonus.c Bonus/ft_check_wall_bonus.c Bonus/ft_function_key_bonus.c Bonus/ft_put_image_to_window_bonus.c Bonus/main_bonus.c \
		Bonus/ft_check_extension_bonus.c Bonus/ft_enemy_bonus.c Bonus/ft_check_moves_bonus.c  Bonus/ft_error_bonus.c Bonus/ft_load_images_bonus.c Bonus/ft_steps_x_y_bonus.c \
		Bonus/ft_check_moves_enemy_bonus.c Bonus/ft_side_enemy_bonus.c

LIBFT_DIR = libft
LIBFT = libft/libft.a 
SRCOB = ${SRC:.c=.o}
BNSOB = ${BNS:.c=.o}
GET_NEXT_LINEOB = ${GET_NEXT_LINE:.c=.o}
HEADERGNL = get_next_line/get_next_line.h
HEADERM = Mandatory/so_long.h
HEADERB = Bonus/so_long_bonus.h 
CC = cc -Wall -Werror -Wextra 
MLX = -L /Users/risattou/Desktop/so1/MLX42 -lmlx42 -lglfw3 -framework Cocoa -framework OpenGL -framework IOKit

${NAME} : ${SRCOB}  ${LIBFT} ${GET_NEXT_LINEOB}
	${CC} ${SRCOB} ${LIBFT} ${GET_NEXT_LINEOB} ${MLX} -o ${NAME}

all : ${NAME} bonus


bonus:  ${BNSOB} ${LIBFT} ${GET_NEXT_LINEOB}
	${CC} ${LIBFT} ${BNSOB} ${GET_NEXT_LINEOB} ${MLX} -o ${NAMEBONUS}

${LIBFT} :
	${MAKE} -C ${LIBFT_DIR}

get_next_line/%.o : get_next_line/%.c ${HEADERGNL}
	${CC} -c $< -o $@

Mandatory/%.o : Mandatory/%.c ${HEADERM}
	${CC} -c $< -o $@

Bonus/%.o : Bonus/%.c ${HEADERB}
	${CC} -c $< -o $@

clean :
	rm -f ${SRCOB} ${BNSOB} ${GET_NEXT_LINEOB}
	${MAKE} -C ${LIBFT_DIR} clean

fclean : clean
	rm -f ${NAME} ${NAMEBONUS}
	${MAKE} -C ${LIBFT_DIR} fclean

re : fclean all

.PHONY : clean

