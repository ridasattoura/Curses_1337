NAME = dd
CC = c++
CFLAGS = -Wall -Wextra -Werror -std=c++98

SRCS = Account.cpp test.cpp
OBJS = $(SRCS:.cpp=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean $(NAME)
	$(CC) $(CFLAGS) -o $(NAME) PhoneBook.o
