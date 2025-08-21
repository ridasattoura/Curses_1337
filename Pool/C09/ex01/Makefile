CFILES = srcs/ft_putchar.c srcs/ft_swap.c srcs/ft_putstr.c srcs/ft_strlen.c srcs/ft_strcmp.c
OBJ =$(CFILES:.c=.o)
CC = gcc -Wall -Wextra -Werror
AR = ar rcs
TARGET = libft.a
INC = includes

all : $(TARGET)

$(TARGET) : $(OBJ)
	$(AR) $@ $(OBJ)

$(OBJ) : $(CFILES)
	$(CC) -c -I$(INC) $< -o $@ 

clean:
	rm -f $(OBJ)

fclean : clean
	rm -f $(TARGET)

re : fclean all

.PHONY : re all clean fclean