/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 03:03:19 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 03:03:20 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handle(int id1, t_shell *shell)
{
	int	status;
	int	sig;

	signal(2, SIG_IGN);
	signal(3, SIG_IGN);
	waitpid(id1, &status, 0);
	if (WIFSIGNALED(status))
	{
		sig = WTERMSIG(status);
		if (sig == 1)
			shell->exit_status = sig;
		else
		{
			shell->exit_status = 128 + sig;
			if (sig == SIGINT)
				write(STDOUT_FILENO, "\n", 1);
			else if (sig == SIGQUIT)
				write(STDOUT_FILENO, "Quit: 3\n", 8);
		}
	}
	else
		shell->exit_status = WEXITSTATUS(status);
	signal(2, ff);
}

bool	run_command(t_shell *shell, int *fdin, int *fdout)
{
	char	*cmnd;

	if (shell->ast_root->full_cmd->cmd)
	{
		cmnd = ft_create_path(shell->ast_root->full_cmd->cmd[0], shell->env,
				&shell->exit_status);
		if (!cmnd)
			exit(shell->exit_status);
		signal(3, SIG_DFL);
		close_2(*fdin, *fdout);
		if (execve(cmnd, shell->ast_root->full_cmd->cmd, shell->env) == -1)
		{
			perror("execve failed");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		signal(3, SIG_DFL);
		close_2(*fdin, *fdout);
		exit(0);
	}
	return (true);
}

void	already_forked(t_shell *shell, int *fdin, int *fdout)
{
	if (shell->ast_root->full_cmd->red_in)
	{
		*fdin = ft_open_file(shell->ast_root->full_cmd, 1, shell->envp_list,
				shell->exit_status);
		if (*fdin == -1)
		{
			perror("failed in");
			shell->exit_status = 1;
			return ;
		}
		dup2(*fdin, 0);
		close(*fdin);
	}
	if (shell->ast_root->full_cmd->red_out)
	{
		*fdout = ft_open_file(shell->ast_root->full_cmd, 0, shell->envp_list,
				shell->exit_status);
		if (*fdout == -1)
		{
			perror("failed out");
			shell->exit_status = 1;
			return ;
		}
		dup2(*fdout, 1);
		close(*fdout);
	}
	if (!run_command(shell, fdin, fdout))
	{
		shell->exit_status = 127;
		return ;
	}
}

void	child_process(t_shell *shell, int *fdin, int *fdout)
{
	signal(2, SIG_DFL);
	if (shell->ast_root->full_cmd->ambigious == 1)
	{
		write(2, "minishell :failed ambiguous redirect\n", 37);
		exit(1);
	}
	if (shell->ast_root->full_cmd->red_in)
	{
		*fdin = ft_open_file(shell->ast_root->full_cmd, 1, shell->envp_list,
				shell->exit_status);
		if (*fdin == -1)
		{
			perror("failed in");
			exit(1);
		}
		dup2(*fdin, 0);
		close(*fdin);
	}
	if (shell->ast_root->full_cmd->red_out)
	{
		*fdout = ft_open_file(shell->ast_root->full_cmd, 0, shell->envp_list,
				shell->exit_status);
		if (*fdout == -1)
		{
			perror("failed out");
			exit(1);
		}
		dup2(*fdout, 1);
		close(*fdout);
	}
	if (!ft_should_fork(shell->ast_root->full_cmd->cmd))
		return (main_builtins(shell, 1), exit(0));
	if (!run_command(shell, fdin, fdout))
		exit(127);
}

void	ft_command(t_shell *shell, int flag)
{
	int	id1;
	int	fdin;
	int	fdout;

	expand_processing(shell, &fdin, &fdout);
	if (ft_should_fork(shell->ast_root->full_cmd->cmd) == -1
		&& is_builtins(shell->ast_root->full_cmd->cmd) != -1)
	{
		main_builtins(shell, 0);
		ft_update_envp(shell, 1);
		return ;
	}
	if (!flag || ft_should_fork(shell->ast_root->full_cmd->cmd) == 0)
	{
		id1 = fork();
		if (id1 == 0)
			child_process(shell, &fdin, &fdout);
		close_2(fdin, fdout);
		signal_handle(id1, shell);
	}
	else
	{
		already_forked(shell, &fdin, &fdout);
		close_2(fdin, fdout);
	}
}

// void	close_2(int in, int out)
// {
// 	close(in);
// 	close(out);
// }
// void	ft_command(t_shell *shell, int flag)
// {
// 	char	*cmnd;
// 	int		id1;
// 	int		status;
// 	int		fdin;
// 	int		fdout;

// 	fdin = -1;
// 	fdout = -1;
// 	expand_processing(shell);
// 	if ((ft_should_fork(shell->ast_root->full_cmd->cmd) == -1)
// 		&& is_builtins(shell->ast_root->full_cmd->cmd) != -1)
// 	{
// 		main_builtins(shell, 0);
// 		ft_update_envp(shell, 1);
// 		return ;
// 	}
// 	if (!flag || ft_should_fork(shell->ast_root->full_cmd->cmd) == 0)
// 	{
// 		id1 = fork();
// 		if (id1 == 0)
// 		{
// 			signal(2, SIG_DFL);
// 			if (shell->ast_root->full_cmd->red_in)
// 			{
// 				fdin = ft_open_file(shell->ast_root->full_cmd,
// 						1, shell->envp_list);
// 				if (fdin == -1)
// 					return (perror("failed in"));
// 				dup2(fdin, 0);
// 				close(fdin);
// 			}
// 			if (shell->ast_root->full_cmd->red_out)
// 			{
// 				fdout = ft_open_file(shell->ast_root->full_cmd,
// 						0, shell->envp_list);
// 				if (fdout == -1)
// 					return (perror("failed out"));
// 				dup2(fdout, 1);
// 				close(fdout);
// 			}
// 			if (!ft_should_fork(shell->ast_root->full_cmd->cmd))
// 			{
// 				main_builtins(shell, 1);
// 				exit(0);
// 			}
// 			cmnd = ft_create_path(shell->ast_root->full_cmd->cmd[0],
// 					shell->env);
// 			if (!cmnd)
// 				exit(127);
// 			signal(3, SIG_DFL);
// 			close(fdout);
// 			close(fdin);
// 			if (execve(cmnd, shell->ast_root->full_cmd->cmd, shell->env) == -1)
// 			{
// 				perror("execvp failed");
// 				exit(EXIT_FAILURE);
// 			}
// 		}
// 		close_2(fdin, fdout);
// 		signal(2, SIG_IGN);
// 		signal(3, SIG_IGN);
// 		waitpid(id1, &status, 0);
// 		int		sig;
// 		if (WIFSIGNALED(status))
// 		{
// 			sig = WTERMSIG(status);
// 			shell->exit_status = 128 + sig;
// 			if (sig == SIGINT)
// 				write(STDOUT_FILENO, "\n", 1);
// 			else if (sig == SIGQUIT)
// 				write(STDOUT_FILENO, "Quit: 3\n", 8);
// 		}
// 		else
// 			shell->exit_status = WEXITSTATUS(status);
// 		signal(2, ff);
// 	}
// 	else
// 	{
// 		if (shell->ast_root->full_cmd->red_in)
// 		{
// 			fdin = ft_open_file(shell->ast_root->full_cmd,
// 					1, shell->envp_list);
// 			if (fdin == -1)
// 				return (perror("failed in"));
// 			dup2(fdin, 0);
// 			close(fdin);
// 		}
// 		if (shell->ast_root->full_cmd->red_out)
// 		{
// 			fdout = ft_open_file(shell->ast_root->full_cmd,
// 					0, shell->envp_list);
// 			if (fdout == -1)
// 				return (perror("failed out"));
// 			dup2(fdout, 1);
// 			close(fdout);
// 		}
// 		cmnd = ft_create_path(shell->ast_root->full_cmd->cmd[0], shell->env);
// 		if (!cmnd)
// 			return ;
// 		signal(3, SIG_DFL);
// 		close(fdout);
// 		close(fdin);
// 		if (execve(cmnd, shell->ast_root->full_cmd->cmd, shell->env) == -1)
// 		{
// 			perror("execvp failed");
// 			exit(EXIT_FAILURE);
// 		}
// 		close(fdout);
// 		close(fdin);
// 	}
// }
