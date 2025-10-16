/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils1.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:58:34 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/08 15:31:57 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	input_files(t_full_cmd *cmd, int *fd, t_env *envp, int exit_status)
{
	if (check_ambiguous(cmd->red_in) == -1)
	{
		write(2, "minishell :failed ambiguous redirect\n", 37);
		exit(1);
	}
	while (cmd->red_in != NULL)
	{
		close(*fd);
		if (cmd->red_in->type == REDIRECT_IN)
			*fd = open(cmd->red_in->value, O_RDONLY);
		else if (cmd->red_in->type == HEREDOC
				|| cmd->red_in->type == EXPAND_HERE_DOC)
		{
			if (cmd->red_in->next == NULL)
				*fd = handle_is_expand(cmd, envp, exit_status);
			else
			{
				cmd->red_in = cmd->red_in->next;
				continue ;
			}
		}
		if (*fd == -1)
			break ;
		cmd->red_in = cmd->red_in->next;
	}
}

void	output_files(t_full_cmd *cmd, int *fd)
{
	if (check_ambiguous(cmd->red_out) == -1)
	{
		write(2, "minishell :failed ambiguous redirect\n", 37);
		exit(1);
	}
	while (cmd->red_out != NULL)
	{
		close(*fd);
		if (cmd->red_out->type == APPEND)
			*fd = open(cmd->red_out->value, O_WRONLY | O_CREAT | O_APPEND,
					0644);
		else if (cmd->red_out->type == REDIRECT_OUT)
			*fd = open(cmd->red_out->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		if (*fd == -1)
			break ;
		cmd->red_out = cmd->red_out->next;
	}
}

int	ft_open_file(t_full_cmd *cmd, int flag, t_env *envp, int exit_status)
{
	int	fd;

	fd = -1;
	if (flag == 1 && (cmd->red_in->type == REDIRECT_IN
			|| cmd->red_in->type == HEREDOC
			|| cmd->red_in->type == EXPAND_HERE_DOC))
		input_files(cmd, &fd, envp, exit_status);
	else if (flag == 0 && (cmd->red_out->type == APPEND
				|| cmd->red_out->type == REDIRECT_OUT))
		output_files(cmd, &fd);
	return (fd);
}

void	expand_loop(t_full_cmd *cmd, t_env *envp, int *fd, int exit_status)
{
	char	*line;
	char	*expanded;

	while (1)
	{
		line = get_next_line(cmd->fd);
		if (!line)
			break ;
		expanded = ft_strdup("");
		check_availabel(envp, line, &expanded, exit_status);
		if (!expanded)
			write(fd[1], "\n", 1);
		else
			write(fd[1], expanded, ft_strlen(expanded));
		free(expanded);
		free(line);
		line = NULL;
	}
}

int	handle_is_expand(t_full_cmd *cmd, t_env *envp, int exit_status)
{
	int	fd[2];

	if (cmd->red_in->type == HEREDOC)
	{
		if (pipe(fd) == -1)
		{
			perror("pipe failed");
			return (-1);
		}
		expand_loop(cmd, envp, fd, exit_status);
		close(cmd->fd);
		close(fd[1]);
		cmd->fd = fd[0];
	}
	return (cmd->fd);
}
