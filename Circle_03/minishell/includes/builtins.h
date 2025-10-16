/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:03:15 by amn               #+#    #+#             */
/*   Updated: 2025/07/08 15:13:19 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H


# include "parsing.h"

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
int	check_valid_export(char **args);


char	*ft_strdup_var(const char *s, int j);
int		ft_strlen_(char *str);
void	print_exp_list(t_env *envp_list);
void	ft_export(t_shell *shell);
int	ft_open_file(t_full_cmd *cmd, int flag, t_env *envp,int exit_status);
void	cleanup(t_shell *shell, t_token *list);
#endif