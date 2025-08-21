/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 07:07:34 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:36:02 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPAND_BONUS_H
# define EXPAND_BONUS_H

# include <stdbool.h>
# include "lexer_bonus.h"
# include "parsing_bonus.h"
# include "../../libft/libft.h"

typedef struct s_norm
{
	int		exit_status;
	int		*is_ambigious;
	t_env	*envp_list;
}			t_norm;

typedef enum e_quote
{
	NO_QUOTE,
	IN_S_QUOTE,
	IN_D_QUOTE
}				t_quote;

typedef struct dirent	t_dir_entry;

typedef struct s_expand_info
{
	t_token	**expanded_list;
	t_token	*first_added;
	bool	found_first;
}	t_expand_info;

void			search_and_add(bool	*found, t_token	**expanded_list,
					t_token *list);
void			core_find(t_token *list, t_dir_entry *entry,
					t_expand_info *info);
void			init_exp(t_norm	*mix, int exit_status,
					int *ambigious, t_env *envp_list);
void			free_list(t_token *list);
int				handle_is_expand(t_full_cmd *cmd, t_env *envp, int exit_status);
int				ft_here_doc_(t_token *file);
void			expand_processing(t_shell *shell, int *fdin, int *fdout);
bool			set_flag_remove(char *str, int *i, t_quote *flag);
bool			has_unquoted_wildcard(char *str);
t_token			*ft_wildcard(t_token *list);
t_full_cmd		*full_wildcard(t_full_cmd *cmd);
char			*remove_first_value_quotes(char *str);
bool			find_files(t_token *list, t_token **expanded_list);
void			remove_quotes_from_tokens(t_token *list);
bool			wildcard_match(char *pattern, const char *filename);
void			exchange_quotes(t_token *cmd);
t_full_cmd		*full_expand(t_full_cmd *cmd,
					t_env *envp_list, int exit_status);
bool			set_flag(char *str, int *i, t_quote *flag);
t_env			*get_variable_envp(t_env *envp_list, char *extract);
char			*expand_variable(const char *str, int *i, t_env *envp_list);
char			*no_expand(char c, char *expanded);
void			free_two(char *one, char *two);
void			additional_handling(t_token *cmd,
					t_token **new, char **expanded);
void			core_handling(int *i, char **expanded,
					t_token *cmd, t_env *envp_list);
t_token_type	expand_check(char *string);
void			code_handle(int *i, char **expanded,
					t_token *cmd, int exit_status);
#endif