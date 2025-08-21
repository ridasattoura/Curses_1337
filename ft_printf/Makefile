NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs

SRC =	ft_printf.c ft_countnbr.c \
	ft_printnegativ.c  ft_printptr.c\
	ft_printstring.c \
	ft_choose.c \
	ft_printnumber.c \
	ft_putchar.c ft_helpnumber.c
SRCB =	ft_printf.c ft_countnbr.c \
	ft_printnegativ.c  ft_printptr.c\
	ft_printstring.c \
	ft_choose.c \
	ft_printnumber.c \
	ft_putchar.c ft_helpnumber.c

OBJ = $(SRC:.c=.o)
OBJB = $(SRCB:.c=.o)

${NAME}: ${OBJ} 

all: $(NAME) bonus

bonus:  $(OBJB)


%.o: %.c ft_printf.h
	$(CC) $(CFLAGS) -c $< 
	$(AR) $(NAME) $@

clean:
	rm -f $(OBJ) $(OBJB)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: clean 