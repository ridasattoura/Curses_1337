CC = cc
CFLAGS = -Wextra -Werror -Wall -Iincludes
# READLINE_PATH = /opt/homebrew/opt/readline
READLINE_PATH = /goinfre/mohchaib/homebrew/opt/readline
CFLAGS += -I$(READLINE_PATH)/include
READLINE = -L$(READLINE_PATH)/lib -lreadline
NAME = minishell
SRCS =  src/builtins/cd.c src/builtins/echo.c src/builtins/env.c src/builtins/exit.c src/builtins/export_helper1.c src/builtins/export_helper2.c src/builtins/export.c src/builtins/main_builtins.c src/builtins/main_builtins_utils.c src/builtins/pwd.c src/builtins/unset.c \
	src/env/envp.c src/env/envp_utils1.c src/env/envp_utils2.c \
	src/exec/command.c src/exec/command_utils1.c src/exec/exec.c src/exec/heredoc.c src/exec/here_doc_utils.c src/exec/or_and.c src/exec/path_relative.c src/exec/pipe.c src/exec/pipe_utils1.c src/exec/redirections.c src/exec/redirections_utils1.c \
	src/expand/expand.c src/expand/expand_utils1.c src/expand/expand_utils2.c src/expand/expand_utils3.c \
	src/lexer/lexer.c src/lexer/lexer_utils1.c src/lexer/lexer_utils2.c src/lexer/lexer_utils3.c \
	src/parser/parser.c src/parser/parser_utils1.c src/parser/parser_utils2.c src/parser/parser_utils3.c src/parser/parser_utils4.c src/parser/parser_utils5.c src/parser/parser_utils6.c \
	src/wildcard/wildcard.c src/wildcard/wildcard_utils1.c src/wildcard/wildcard_utils2.c \
	src/main.c get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)
LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

all: $(LIBFT) $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LIBFT) $(READLINE) 

$(LIBFT):
	$(MAKE) -C $(LIBFT_DIR) bonus all

%.o: %.c includes/*.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS)
	$(MAKE) -C $(LIBFT_DIR) clean

fclean: clean
	rm -rf $(NAME)
	$(MAKE) -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re


