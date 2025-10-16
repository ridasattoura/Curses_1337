NAME = push_swap
NAMEBONUS = checker

SRC =	Mandatory/ft_atoi_check.c Mandatory/ft_atoi.c Mandatory/ft_error.c Mandatory/ft_lstadd_back.c Mandatory/ft_lstadd_front.c \
		Mandatory/ft_lstclear.c Mandatory/ft_lstlast.c Mandatory/ft_lstnew.c Mandatory/ft_lstsize.c Mandatory/ft_is_sorted.c \
		Mandatory/ft_putstr.c Mandatory/ft_sort_five_or_less.c Mandatory/ft_sortlist.c Mandatory/ft_split_check.c \
		Mandatory/ft_split.c Mandatory/main_sort.c Mandatory/main.c Mandatory/rules_part_one.c Mandatory/rules_part_two.c

BNS =	Bonus/ft_atoi_check_bonus.c Bonus/ft_atoi_bonus.c Bonus/ft_error_bonus.c Bonus/ft_lstadd_back_bonus.c Bonus/ft_lstadd_front_bonus.c \
		Bonus/ft_lstclear_bonus.c Bonus/ft_lstlast_bonus.c Bonus/ft_lstnew_bonus.c Bonus/ft_lstsize_bonus.c Bonus/ft_is_sorted_bonus.c \
		Bonus/ft_putstr_bonus.c  Bonus/ft_sortlist_bonus.c Bonus/ft_split_check_bonus.c \
		Bonus/ft_split_bonus.c Bonus/main_sort_bonus.c Bonus/main_bonus.c Bonus/rules_part_one_bonus.c Bonus/rules_part_two_bonus.c \
		Bonus/get_next_line/get_next_line.c Bonus/get_next_line/get_next_line_utils.c Bonus/ft_strcmp.c Bonus/rules_part_three_bonus.c

SRCOB = ${SRC:.c=.o}
BNSOB = ${BNS:.c=.o}
HEADERM = Mandatory/pushswap.h
HEADERB = Bonus/pushswap_bonus.h
CC = cc
FLAGS = -Wall -Wextra -Werror 

${NAME}: ${SRCOB} 
	${CC} ${FLAGS} ${SRCOB} -o ${NAME}

all: ${NAME} bonus

bonus:  ${BNSOB} 
	${CC} ${FLAGS} ${BNSOB} -o ${NAMEBONUS}

%.o : %.c 
	${CC} ${FLAGS} -c $< -o $@

clean:
	rm -f ${SRCOB} ${BNSOB}

fclean: clean
	rm -f ${NAME} ${NAMEBONUS}

re: fclean all

.PHONY: all clean fclean re