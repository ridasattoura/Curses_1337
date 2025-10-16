/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 13:04:58 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 03:02:59 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSING_H
# define PARSING_H

# include "lexer.h"
# include <stdbool.h>

# define SYNTAX "\tSyntax error: "
# define ERR0 "\tError: allocation fail\n"
# define ERR1 "command or redirection directly beside parenthesis\n"
# define ERR2 "parentheses need logical OP before '(' or after ')'\n"
# define ERR3 "empty parenthesis\n"
# define ERR4 "missing open parenthesis\n"
# define ERR5 "unbalanced parenthesis\n"
# define ERR6 "operator at the start of the command\n"
# define ERR7 "operator followed by another operator\n"
# define ERR8 "operator at the end of the command\n"
# define ERR9 "redirection not followed by a file\n"
# define ERR10 "unclosed quote\n"
# define ERR11 "\tError: failed to open current directory\n"


typedef struct s_context
{
	t_token			*list;
	int				precedence;
	int				depth;
	int				lowest_precedence;
	bool			subshell;
}					t_context;
	
typedef struct s_full_cmd
{
	t_token			*red_out;
	t_token			*red_in;
	t_token			*args;
	int 			fd;
	char			**cmd;
	int				ambigious;
}					t_full_cmd;

typedef struct s_ast
{
	t_token_type	type;
	t_full_cmd		*full_cmd;
	struct s_ast	*left;
	struct s_ast	*right;
}					t_ast;

typedef struct s_env
{
	struct s_env	*next;
	char			*variable;
	char			*value;
	bool			is_export;
}					t_env;

typedef struct s_shell
{
	t_ast			*ast_root;
	char			**env;
	t_env			*envp_list;
	int				exit_status;
}					t_shell;

char		*token_type_str(t_token_type type);
int			get_precedence(t_token_type type);
bool		is_parenthesis(t_token_type type);
bool		is_ast_operator(t_token_type type);
bool		check_parenthesis_logic(t_token *list);
bool		check_balanced_parentheses(t_token *head);
void		detach_node(t_token *node, int remove);
void		trim_parenthesis(t_token **list);
void		free_tree(t_ast *tree);
bool		is_logic_token(t_token *tok);
bool		is_cmd_or_redir(t_token *tok);
t_token		*find_matching_close(t_token *open);
bool		check_paren_logic(t_token *start, t_token *end);
bool		consecutive_operators(t_token *head);
void		depth_check(t_token *token, int *depth, bool *subshell);
t_token		*find_branch_root(t_context *context);
void		ft_print_error(int error);
void		init_context_stucture(t_context *context, t_token *list);
t_ast		*branch_root(t_token *branch, t_token *list);
t_ast		*parenthesis(t_token *list);
t_ast		*commands(t_token *list);
t_ast		*create_tree(t_token *list);
bool		syntax_error(t_token *list, t_shell *);
void		print_token_list(t_token *list);
void		free_list(t_token *list);
void		remove_node(t_token **list, t_token *node);
t_ast		*new_tree_node(t_token_type type, t_full_cmd *full_cmd);
bool		is_redirection(t_token_type type);
bool		redirection_handle(t_token **list);
char		**transform_args( t_token *args);
t_full_cmd	*init_cmd(void);
t_full_cmd	*commands_handle(t_token **list, t_full_cmd	*cmd);
#endif