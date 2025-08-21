/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:33:42 by risattou          #+#    #+#             */
/*   Updated: 2025/07/05 06:56:43 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	close_pipe(int *fd)
{
	close(fd[0]);
	close(fd[1]);
}

void	first_fork(t_shell *shell, int *fd, int flag)
{
	signal(2, SIG_DFL);
	dup2(fd[1], STDOUT_FILENO);
	close_pipe(fd);
	shell->ast_root = shell->ast_root->left;
	exec(shell, ++flag);
	exit(shell->exit_status);
}

void	second_fork(t_shell *shell, int *fd, int flag)
{
	signal(2, SIG_DFL);
	dup2(fd[0], STDIN_FILENO);
	close_pipe(fd);
	shell->ast_root = shell->ast_root->right;
	exec(shell, ++flag);
	exit(shell->exit_status);
}

void	exit_code(t_shell *shell)
{
	shell->exit_status = 1;
}

void	ft_pipe(t_shell *shell, int flag)
{
	int	fd[2];
	int	id1;
	int	id2;

	if (pipe(fd) == -1)
	{
		perror("pipe failed");
		shell->exit_status = 1;
		return ;
	}
	id1 = fork();
	if (id1 == -1)
		return (perror("fork failed (id1)"), exit_code(shell));
	if (id1 == 0)
		first_fork(shell, fd, flag);
	id2 = fork();
	if (id2 == -1)
		return (perror("fork failed (id2)"), exit_code(shell));
	if (id2 == 0)
		second_fork(shell, fd, flag);
	close_pipe(fd);
	signal_handling(id1, id2, shell);
}
