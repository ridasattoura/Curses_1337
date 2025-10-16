/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:20:50 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 20:07:13 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
// #include <csignal>

void	close_heredoc_fds(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == COMMAND && ast->full_cmd && ast->full_cmd->fd != -1)
	{
		close(ast->full_cmd->fd);
		ast->full_cmd->fd = -1;
	}
	close_heredoc_fds(ast->left);
	close_heredoc_fds(ast->right);
}

static void	handle_here_doc_input(char *av, int fdin)
{
	char	*line;

	while (1)
	{
		line = readline("> ");
		if (!line)
			break ;
		if ((ft_strncmp(line, av, ft_strlen(av)) == 0)
			&& ft_strlen(line) == ft_strlen(av))
		{
			free(line);
			line = NULL;
			break ;
		}
		write(fdin, line, ft_strlen(line));
		write(fdin, "\n", 1);
		free(line);
	}
}

static void	handle_all_heredocs(t_token *file, int fd)
{
	t_token	*current;

	current = file;
	while (current != NULL)
	{
		if (current->type == HEREDOC)
		{
			handle_here_doc_input(current->value, fd);
		}
		current = current->next;
	}
}

bool	core_here_doc(int fd[], t_token *file, int	*prev_fd)
{
	int	id1;
	int	status;

	if (pipe(fd) == -1)
		return (perror("pipe failed"), false);
	id1 = fork();
	if (id1 == -1)
		return (perror("fork failed"), false);
	if (id1 == 0)
	{
		signal(SIGINT, SIG_DFL);
		close(fd[0]);
		handle_all_heredocs(file, fd[1]);
		close(fd[1]);
		exit(EXIT_SUCCESS);
	}
	signal(SIGINT, SIG_IGN);
	waitpid(id1, &status, 0);
	signal(SIGINT, ff);
	close(fd[1]);
	
	// Check if child was terminated by signal (SIGINT)
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(fd[0]);
		*prev_fd = -2;  // Signal interrupted
		return (true);
	}
	
	*prev_fd = fd[0];
	return (true);
}

int	ft_here_doc_(t_token *file)
{
	int	prev_fd;
	int	fd[2];
	t_token *current;
	bool has_heredoc;

	prev_fd = -1;
	fd[0] = -1;
	fd[1] = -1;
	has_heredoc = false;
	
	// Check if there are any heredocs
	current = file;
	while (current != NULL)
	{
		if (current->type == HEREDOC)
		{
			has_heredoc = true;
			break;
		}
		current = current->next;
	}
	
	// Fork once for all heredocs if any exist
	if (has_heredoc)
	{
		if (!core_here_doc(fd, file, &prev_fd))
			return (-1);
		// If signal interrupted, return -2
		if (prev_fd == -2)
			return (-2);
	}
	
	return (prev_fd); 
}

void	ft_here_doc(char *value, int files[2])
{
	handle_here_doc_input(value, files[1]);
	close(files[1]); 
}
