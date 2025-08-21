/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils1_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:58:34 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:07:49 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	input_files(t_full_cmd *cmd, int *fd, t_env *envp, int exit_status)
{
	t_token	*temp;

	temp = cmd->red_in;
	while (temp != NULL)
	{
		close(*fd);
		if (temp->type == REDIRECT_IN)
			check_string(temp, fd);
		else if (temp->type == HEREDOC || temp->type == EXPAND_HERE_DOC)
		{
			if (temp->next == NULL)
				*fd = handle_is_expand(cmd, envp, exit_status);
			else
			{
				temp = temp->next;
				continue ;
			}
		}
		else
			return (printf(ERR12), exit(1));
		if (*fd == -1)
			break ;
		temp = temp->next;
	}
}

void	output_files(t_full_cmd *cmd, int *fd)
{
	t_token	*temp;

	temp = cmd->red_out;
	while (temp != NULL)
	{
		close(*fd);
		if (temp->type == APPEND)
		{
			if (ft_strlen(temp->value) == 0)
				return (printf(ERR12), exit(1));
			*fd = open(temp->value, O_WRONLY | O_CREAT | O_APPEND, 0644);
		}
		else if (temp->type == REDIRECT_OUT)
		{
			if (ft_strlen(temp->value) == 0)
				return (printf(ERR12), exit(1));
			*fd = open(temp->value, O_WRONLY | O_CREAT | O_TRUNC, 0644);
		}
		else
			return (printf(ERR12), exit(1));
		if (*fd == -1)
			break ;
		temp = temp->next;
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
