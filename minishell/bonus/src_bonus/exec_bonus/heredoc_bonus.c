/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heredoc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/08 19:20:50 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:38 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	handle_parent_process(int id1, int fd[], int *prev_fd)
{
	int	status;

	signal(SIGINT, SIG_IGN);
	waitpid(id1, &status, 0);
	signal(SIGINT, ff);
	close(fd[1]);
	if (WIFSIGNALED(status) && WTERMSIG(status) == SIGINT)
	{
		close(fd[0]);
		*prev_fd = -2;
		return (true);
	}
	*prev_fd = fd[0];
	return (true);
}

bool	core_here_doc(int fd[], t_token *file, int *prev_fd)
{
	int	id1;

	if (pipe(fd) == -1)
		return (perror("pipe failed"), false);
	id1 = fork();
	if (id1 == -1)
		return (perror("fork failed"), false);
	if (id1 == 0)
		handle_child_process(fd, file);
	return (handle_parent_process(id1, fd, prev_fd));
}

bool	check_heredoc_exists(t_token *file)
{
	t_token	*current;

	current = file;
	while (current != NULL)
	{
		if (current->type == HEREDOC)
			return (true);
		current = current->next;
	}
	return (false);
}

int	ft_here_doc_(t_token *file)
{
	int		prev_fd;
	int		fd[2];

	prev_fd = -1;
	fd[0] = -1;
	fd[1] = -1;
	if (check_heredoc_exists(file))
	{
		if (!core_here_doc(fd, file, &prev_fd))
			return (-1);
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
