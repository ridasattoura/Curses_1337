CC = cc
CFLAGS = -Wextra -Werror -Wall #-fsanitize=address -g
READLINE_PATH = /goinfre/mohchaib/homebrew/opt/readline
# READLINE_PATH = /opt/homebrew/opt/readline
CFLAGS += -I$(READLINE_PATH)/include
READLINE = -L$(READLINE_PATH)/lib -lreadline
NAME = minishell
BONUS_FLAG = .bonus
MANDATORY_DIR = Mandatory
BONUS_DIR = bonus
LIBFT_DIR = libft
GNL_DIR = get_next_line


MANDATORY_INCLUDES = -I$(MANDATORY_DIR)/includes
BONUS_INCLUDES = -I$(BONUS_DIR)/includes_bonus


LIBFT = $(LIBFT_DIR)/libft.a


MANDATORY_SRCS = $(MANDATORY_DIR)/main.c \
				$(MANDATORY_DIR)/main_helper.c \
				$(MANDATORY_DIR)/builtins/cd.c \
				$(MANDATORY_DIR)/builtins/cd_utils1.c \
				$(MANDATORY_DIR)/builtins/echo.c \
				$(MANDATORY_DIR)/builtins/env.c \
				$(MANDATORY_DIR)/builtins/exit.c \
				$(MANDATORY_DIR)/builtins/export.c \
				$(MANDATORY_DIR)/builtins/export_helper1.c \
				$(MANDATORY_DIR)/builtins/export_helper2.c \
				$(MANDATORY_DIR)/builtins/main_builtins.c \
				$(MANDATORY_DIR)/builtins/main_builtins_utils.c \
				$(MANDATORY_DIR)/builtins/pwd.c \
				$(MANDATORY_DIR)/builtins/unset.c \
				$(MANDATORY_DIR)/env/envp.c \
				$(MANDATORY_DIR)/env/envp_utils1.c \
				$(MANDATORY_DIR)/env/envp_utils2.c \
				$(MANDATORY_DIR)/exec/command.c \
				$(MANDATORY_DIR)/exec/command_utils1.c \
				$(MANDATORY_DIR)/exec/command_utils2.c \
				$(MANDATORY_DIR)/exec/exec.c \
				$(MANDATORY_DIR)/exec/here_doc_utils.c \
				$(MANDATORY_DIR)/exec/here_doc_utils1.c \
				$(MANDATORY_DIR)/exec/heredoc.c \
				$(MANDATORY_DIR)/exec/path_relative.c \
				$(MANDATORY_DIR)/exec/path_relative_utils1.c \
				$(MANDATORY_DIR)/exec/pipe.c \
				$(MANDATORY_DIR)/exec/pipe_utils1.c \
				$(MANDATORY_DIR)/exec/redirections.c \
				$(MANDATORY_DIR)/exec/redirections_utils1.c \
				$(MANDATORY_DIR)/exec/redirections_utils2.c \
				$(MANDATORY_DIR)/expand/expand.c \
				$(MANDATORY_DIR)/expand/expand_utils1.c \
				$(MANDATORY_DIR)/expand/expand_utils2.c \
				$(MANDATORY_DIR)/expand/expand_utils3.c \
				$(MANDATORY_DIR)/lexer/lexer.c \
				$(MANDATORY_DIR)/lexer/lexer_utils1.c \
				$(MANDATORY_DIR)/lexer/lexer_utils2.c \
				$(MANDATORY_DIR)/lexer/lexer_utils3.c \
				$(MANDATORY_DIR)/parser/parser.c \
				$(MANDATORY_DIR)/parser/parser_utils1.c \
				$(MANDATORY_DIR)/parser/parser_utils2.c \
				$(MANDATORY_DIR)/parser/parser_utils3.c \
				$(MANDATORY_DIR)/parser/parser_utils4.c \
				$(MANDATORY_DIR)/parser/parser_utils5.c \
				$(MANDATORY_DIR)/parser/parser_utils6.c \
				$(GNL_DIR)/get_next_line.c \
				$(GNL_DIR)/get_next_line_utils.c


BONUS_SRCS = $(BONUS_DIR)/src_bonus/main_bonus.c \
			$(BONUS_DIR)/src_bonus/main_helper_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/cd_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/cd_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/echo_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/env_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/exit_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/export_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/export_helper1_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/export_helper2_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/main_builtins_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/main_builtins_utils_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/pwd_bonus.c \
			$(BONUS_DIR)/src_bonus/builtins_bonus/unset_bonus.c \
			$(BONUS_DIR)/src_bonus/env_bonus/envp_bonus.c \
			$(BONUS_DIR)/src_bonus/env_bonus/envp_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/env_bonus/envp_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/command_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/command_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/command_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/exec_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/here_doc_utils_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/here_doc_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/heredoc_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/or_and_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/path_relative_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/path_relative_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/pipe_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/pipe_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/redirections_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/redirections_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/exec_bonus/redirections_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/expand_bonus/expand_bonus.c \
			$(BONUS_DIR)/src_bonus/expand_bonus/expand_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/expand_bonus/expand_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/expand_bonus/expand_utils3_bonus.c \
			$(BONUS_DIR)/src_bonus/lexer_bonus/lexer_bonus.c \
			$(BONUS_DIR)/src_bonus/lexer_bonus/lexer_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/lexer_bonus/lexer_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/lexer_bonus/lexer_utils3_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils2_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils3_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils4_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils5_bonus.c \
			$(BONUS_DIR)/src_bonus/parser_bonus/parser_utils6_bonus.c \
			$(BONUS_DIR)/src_bonus/wildcard_bonus/wildcard_bonus.c \
			$(BONUS_DIR)/src_bonus/wildcard_bonus/wildcard_utils1_bonus.c \
			$(BONUS_DIR)/src_bonus/wildcard_bonus/wildcard_utils2_bonus.c \
			$(GNL_DIR)/get_next_line.c \
			$(GNL_DIR)/get_next_line_utils.c


MANDATORY_OBJS = $(MANDATORY_SRCS:.c=.o)
BONUS_OBJS = $(BONUS_SRCS:.c=.o)

# Objects specific to each build (excluding shared GNL objects)
MANDATORY_ONLY_OBJS = $(filter-out $(GNL_DIR)/%,$(MANDATORY_OBJS))
BONUS_ONLY_OBJS = $(filter-out $(GNL_DIR)/%,$(BONUS_OBJS))


GREEN = \033[0;32m
RED = \033[0;31m
BLUE = \033[0;34m
YELLOW = \033[0;33m
NC = \033[0m 


all: $(LIBFT) $(NAME)


$(NAME): $(MANDATORY_OBJS) $(LIBFT)
	@rm -f $(BONUS_FLAG)
	@rm -f $(BONUS_ONLY_OBJS)
	@echo "$(GREEN)Linking mandatory minishell...$(NC)"
	@$(CC) $(CFLAGS) $(MANDATORY_INCLUDES) -o $(NAME) $(MANDATORY_OBJS) $(LIBFT) $(READLINE)
	@echo "$(GREEN)✓ Mandatory minishell compiled successfully!$(NC)"


bonus: $(BONUS_FLAG)

$(BONUS_FLAG): $(BONUS_OBJS) $(LIBFT)
	@rm -f $(MANDATORY_ONLY_OBJS)
	@echo "$(YELLOW)Removing previous executable...$(NC)"
	@rm -f $(NAME)
	@echo "$(BLUE)Linking bonus minishell...$(NC)"
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -o $(NAME) $(BONUS_OBJS) $(LIBFT) $(READLINE)
	@echo "$(BLUE)✓ Bonus minishell compiled successfully!$(NC)"
	@touch $(BONUS_FLAG)


$(LIBFT):
	@echo "$(YELLOW)Building libft...$(NC)"
	@$(MAKE) -C $(LIBFT_DIR) bonus


MANDATORY_HEADERS = $(MANDATORY_DIR)/includes/minishell.h \
					$(MANDATORY_DIR)/includes/lexer.h \
					$(MANDATORY_DIR)/includes/parsing.h \
					$(MANDATORY_DIR)/includes/execution.h \
					$(MANDATORY_DIR)/includes/expand.h \
					$(MANDATORY_DIR)/includes/builtins.h

BONUS_HEADERS = $(BONUS_DIR)/includes_bonus/minishell_bonus.h \
				$(BONUS_DIR)/includes_bonus/lexer_bonus.h \
				$(BONUS_DIR)/includes_bonus/parsing_bonus.h \
				$(BONUS_DIR)/includes_bonus/execution_bonus.h \
				$(BONUS_DIR)/includes_bonus/expand_bonus.h \
				$(BONUS_DIR)/includes_bonus/builtins_bonus.h

GNL_HEADERS = $(GNL_DIR)/get_next_line.h


$(MANDATORY_DIR)/%.o: $(MANDATORY_DIR)/%.c $(MANDATORY_HEADERS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(MANDATORY_INCLUDES) -c $< -o $@

$(GNL_DIR)/%.o: $(GNL_DIR)/%.c $(MANDATORY_HEADERS) $(GNL_HEADERS)
	@echo "$(GREEN)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(MANDATORY_INCLUDES) -c $< -o $@


$(BONUS_DIR)/%.o: $(BONUS_DIR)/%.c $(BONUS_HEADERS)
	@echo "$(BLUE)Compiling $<...$(NC)"
	@$(CC) $(CFLAGS) $(BONUS_INCLUDES) -c $< -o $@


clean:
	@echo "$(RED)Cleaning object files...$(NC)"
	@rm -f $(MANDATORY_OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) clean
	@echo "$(RED)✓ Object files cleaned!$(NC)"


fclean: clean
	@echo "$(RED)Cleaning executable and libraries...$(NC)"
	@rm -f $(NAME) $(BONUS_FLAG)
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@echo "$(RED)✓ Everything cleaned!$(NC)"


re: fclean all


re_bonus: fclean bonus


help:
	@echo "$(YELLOW)Available targets:$(NC)"
	@echo "  $(GREEN)make$(NC)        - Build mandatory version"
	@echo "  $(BLUE)make bonus$(NC)  - Build bonus version (with wildcards, && ||)"
	@echo "  $(RED)make clean$(NC)  - Remove object files"
	@echo "  $(RED)make fclean$(NC) - Remove object files and executable"
	@echo "  $(YELLOW)make re$(NC)     - Rebuild mandatory version"
	@echo "  $(BLUE)make re_bonus$(NC) - Rebuild bonus version"
	@echo "  $(YELLOW)make help$(NC)   - Show this help message"


.PHONY: all bonus clean fclean re re_bonus help

.SILENT: all bonus clean fclean re re_bonus help