NAME = pipex

MANDATORY_SRCS =  	Mandatory/ft_split_qouts.c Mandatory/get_env_paths.c Mandatory/get_path_cmnds.c Mandatory/main.c \
					Mandatory/pipe.c Mandatory/open_files.c Mandatory/utiles.c Mandatory/ft_count_arg.c \
					Mandatory/ft_helper.c 

BONUS_SRCS =  	Bonus/ft_split_qouts_bonus.c Bonus/get_env_paths_bonus.c Bonus/get_path_cmnds_bonus.c Bonus/main_bonus.c \
				Bonus/pipe_bonus.c Bonus/open_files_bonus.c Bonus/utiles_bonus.c Bonus/ft_count_arg_bonus.c Bonus/ft_helper_bonus.c \
				Bonus/here_doc_bonus.c

GET_NEXT_LINE = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

MANDATORY_OBJ = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJ = $(BONUS_SRCS:.c=.o)
OB_GNL = $(GET_NEXT_LINE:.c=.o)

HEADER_Mandatory = Mandatory/pipex.h
HEADER_Bonus = Bonus/pipex_bonus.h
HEADER_GNL = get_next_line/get_next_line.h

LIBFT = libft/libft.a
LIBFT_DIR = libft

CC = cc 
CFLAGS = -Wall -Wextra -Werror #-fsanitize=address -g
RM = rm -f

$(NAME): $(MANDATORY_OBJ) $(OB_GNL) $(LIBFT)
	@rm -f $(BONUS_OBJ)
	$(CC) $(CFLAGS) $(MANDATORY_OBJ) $(OB_GNL) $(LIBFT) -o $(NAME)

all: $(NAME) 

${LIBFT} :
	${MAKE} -C ${LIBFT_DIR}



Mandatory/%.o: Mandatory/%.c $(HEADER_Mandatory)
	$(CC) $(CFLAGS) -c $< -o $@

Bonus/%.o: Bonus/%.c $(HEADER_Bonus)
	$(CC) $(CFLAGS) -c $< -o $@

get_next_line/%.o: get_next_line/%.c $(HEADER_GNL)
	$(CC) $(CFLAGS) -c $< -o $@


bonus: $(BONUS_OBJ) $(OB_GNL) $(LIBFT)
	@rm -f $(MANDATORY_OBJ)
	$(CC) $(CFLAGS) $(BONUS_OBJ) $(OB_GNL) $(LIBFT) -o $(NAME)

clean:
	$(RM) $(MANDATORY_OBJ) $(BONUS_OBJ) $(OB_GNL)
	@${MAKE} -C ${LIBFT_DIR} clean

fclean: clean
	$(RM) $(NAME)
	@${MAKE} -C ${LIBFT_DIR} fclean


re: fclean all

.PHONY: all clean fclean re