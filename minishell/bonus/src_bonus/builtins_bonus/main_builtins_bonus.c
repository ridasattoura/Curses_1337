/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtins_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 10:44:53 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:06 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	choose_function(int i, t_shell *shell)
{
	if (i == 0)
		ft_cd(shell);
	else if (i == 1)
		ft_echo(shell);
	else if (i == 2)
		print_env_list(shell);
	else if (i == 3)
		ft_exit(shell);
	else if (i == 4)
		ft_export(shell);
	else if (i == 5)
		ft_pwd(shell);
	else if (i == 6)
		ft_unset(shell);
	else
		shell->exit_status = 127;
}

int	find_match1(t_shell *shell)
{
	if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "cd", ft_strlen("cd")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("cd"))
			return (0);
	}
	else if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "echo",
			ft_strlen("echo")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("echo"))
			return (1);
	}
	else if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "env",
			ft_strlen("env")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("env"))
			return (2);
	}
	return (-1);
}

int	find_match2(t_shell *shell)
{
	if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "exit",
			ft_strlen("exit")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("exit"))
			return (3);
	}
	else if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "export",
			ft_strlen("export")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("export"))
			return (4);
	}
	else if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "pwd",
			ft_strlen("pwd")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("pwd"))
			return (5);
	}
	else if (!ft_strncmp(shell->ast_root->full_cmd->cmd[0], "unset",
			ft_strlen("unset")))
	{
		if (ft_strlen(shell->ast_root->full_cmd->cmd[0]) == ft_strlen("unset"))
			return (6);
	}
	return (-1);
}

void	red_conditions(t_shell *shell, int flag)
{
	int	fd;

	if (shell->ast_root->full_cmd->red_in && flag == 0)
	{
		fd = ft_open_file(shell->ast_root->full_cmd, 1, shell->envp_list,
				shell->exit_status);
		if (fd == -1)
		{
			perror("failed in");
			shell->exit_status = 1;
			return ;
		}
	}
	if (shell->ast_root->full_cmd->red_out && flag == 0)
	{
		fd = ft_open_file(shell->ast_root->full_cmd, 0, shell->envp_list,
				shell->exit_status);
		if (fd == -1)
		{
			perror("failed in");
			shell->exit_status = 1;
			return ;
		}
	}
	close(fd);
}

int	main_builtins(t_shell *shell, int flag)
{
	int	i;

	i = find_match1(shell);
	if (i == -1)
		i = find_match2(shell);
	red_conditions(shell, flag);
	choose_function(i, shell);
	return (i);
}
