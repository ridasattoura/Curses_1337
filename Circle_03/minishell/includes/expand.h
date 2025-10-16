/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 07:07:34 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 03:07:46 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef EXPAND_H
# define EXPAND_H


# include <stdbool.h>
# include "lexer.h"
# include "parsing.h"
# include "../libft/libft.h"

typedef struct s_norm
{
	int exit_status;
	int is_export;
	int *is_ambigious;
}	t_norm;

typedef enum e_quote
{
	NO_QUOTE,
	IN_S_QUOTE,
	IN_D_QUOTE
}				t_quote;

typedef struct dirent t_dir_entry;

void			free_list(t_token *list);
int				handle_is_expand(t_full_cmd *cmd, t_env *envp,int exit_status);
void			ft_here_doc(char *value, int files[2]);
int 			ft_here_doc_(t_token *file);
t_token			*ft_here_doc_expand(t_token *cmd);
void			expand_processing(t_shell *shell, int*, int*);
bool			set_flag_remove(char *str, int *i, t_quote *flag);
bool			has_unquoted_wildcard(char *str);
t_token			*ft_wildcard(t_token *list);
t_full_cmd		*full_wildcard(t_full_cmd *cmd);
char			*remove_first_value_quotes(char *str);
void			core_find(t_token *list, t_dir_entry *entry,
					bool *found_first, t_token **expanded_list);
bool			find_files(t_token *list, t_token **expanded_list);
void			remove_quotes_from_tokens(t_token *list);
bool			wildcard_match(char *pattern, const char *filename);
// void			core_handling0(int *i, char *str, int exit_status, char **expanded);
// void			expand_token(t_token *cmd, t_env *envp_list, t_token **new, int exit_status);
void			exchange_quotes(t_token *cmd);
// t_token			*ft_expand(t_token *cmd, t_env *envp_list, int exit_status);
t_full_cmd		*full_expand(t_full_cmd *cmd, t_env *envp_list, int exit_status);
bool			set_flag(char *str, int *i, t_quote *flag);
t_env			*get_variable_envp(t_env *envp_list, char *extract);
char			*expand_variable(const char *str, int *i, t_env *envp_list);
char			*no_expand(char c, char *expanded);
void			free_two(char *one, char *two);
void			additional_handling(t_token *cmd, t_token **new, char **expanded);
void			core_handling(int *i, char **expanded, t_token *cmd, t_env *envp_list);
char			*handle_expand_codes(int *i, char *str, int exit_status);
t_token_type	expand_check(char *string);
void			remove_quotes_heredoc(char *string, char **expanded, t_quote *flag);
void			init_expand(int *i, t_quote *flag,	int *did_expand, char **expanded);
#endif