/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execution_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:03:39 by amn               #+#    #+#             */
/*   Updated: 2025/07/09 16:36:12 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTION_BONUS_H
# define EXECUTION_BONUS_H

# include <sys/stat.h> 
# include "parsing_bonus.h"

t_token	*loop_here(t_token	*current);
void	ft_free(char **array);
char	**ft_get_path(char **env);
char	*check_absolute_path(char *command);
char	*search_in_path(char *command, char **path);
void	close_2(int in, int out);
void	close_pipe(int *fd);
void	her_her(t_ast *ast_root, int *exit_status);
void	close_heredoc_fds(t_ast *ast);
void	exec(t_shell *shell, int flag);
void	free_envp(t_env *envp_list, char **envp);
char	**get_env(t_env *envp_list);
char	*ft_strjoin_(char *s1, char *s2);
void	free_matrix(char **matrix);
void	free_matrix_(char **matrix, int i);
int		ft_should_fork(char **av);
int		is_builtins(char **av);
void	ft_update_envp(t_shell *shell, int flag);
char	*ft_create_path(char *cmnd, char **envp, int *exit_status);
char	**transform_args( t_token *args);
void	ft_pipe(t_shell *shell, int flag);
void	ft_command(t_shell *shell, int flag);
void	ft_or(t_shell *shell);
void	ft_and(t_shell *shell);
void	signal_handling(int id1, int id2, t_shell *shell);
int		check_ambiguous(t_token *file);
void	check_availabel(t_env *envp, char *line,
			char **expanded, int exit_status);
t_env	*envp_list(char **envp);
void	red_conditions(t_shell *shell, int flag);
void	choose_function(int i, t_shell *shell);
void	error_handle(t_shell *shell, int flag);
void	ambiguous_handle_(t_shell *shell);
char	*resolve_command_path(char *command, char **path);
int		check_directory_error(char *cmnd, int *exit_status);
void	print_command_not_found(char *cmnd, int *exit_status);
char	*ft_create_path(char *cmnd, char **envp, int *exit_status);
void	her_her(t_ast *ast_root, int *exit_status);
void	close_heredoc_fds(t_ast *ast);
void	handle_here_doc_input(char *av, int fdin);
void	handle_all_heredocs(t_token *file, int fd);
void	handle_child_process(int fd[], t_token *file);
#endif