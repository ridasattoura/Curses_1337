/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_bonus.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:03:15 by amn               #+#    #+#             */
/*   Updated: 2025/07/20 17:02:37 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_BONUS_H
# define BUILTINS_BONUS_H

# include "parsing_bonus.h"

char	*simple_operation2(t_env *temp);
void	check_string(t_token *temp, int *fd);
void	ambiguous_redirection(t_ast *tree);
void	update_or_create_var(t_shell *shell, char *var_name, char *value);
void	update_env_variables(t_shell *shell, char *old_pwd, char *new_pwd);
char	*simple_operation(char *value, char *re);
bool	init_cd(t_env **new_var, char *var_name, char *value);
void	ambiguous_handle(t_token *list);
void	ft_cd(t_shell *shell);
void	ft_echo(t_shell *shell);
void	print_env_list(t_shell *shell);
void	ft_exit(t_shell *shell);
void	ft_export(t_shell *shell);
int		ft_check_var(t_env *head, char *str);
t_env	*ft_creat_var(char *str);
int		main_builtins(t_shell *shell, int flag);
void	ft_pwd(t_shell *shell);
void	ft_unset(t_shell *shell);
int		check_valid_export(char **args);
char	*ft_strdup_var(const char *s, int j);
int		ft_strlen_(char *str);
void	print_exp_list(t_env *envp_list);
void	ft_export(t_shell *shell);
int		ft_open_file(t_full_cmd *cmd, int flag, t_env *envp, int exit_status);
void	cleanup(t_shell *shell, t_token *list);
#endif