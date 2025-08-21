/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:11:30 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 21:40:04 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"
#include <sys/fcntl.h>

static void	handle_here_doc_input(char **av, int fdin)
{
	char	*line;

	while (1)
	{
		write(1, ">", 1); 
		line = get_next_line(0);
		if (!line)
			break ;
		if ((ft_strncmp(line, av[2], ft_strlen(av[2])) == 0) && ft_strlen(line)
			- 1 == ft_strlen(av[2]))
		{
			free(line);
			line = NULL;
			break ;
		}
		write(fdin, line, ft_strlen(line));
		free(line);
		line = NULL;
	}
	if (line)
		free(line);
}

t_files	ft_here_doc(char **av, int ac)
{
	t_files	files;

	if (pipe(files.fd) == -1)
	{
		perror("faild pipe");
		files.fdin = -1;
		files.fdout = -1;
		return (files);
	}
	handle_here_doc_input(av, files.fd[1]);
	close(files.fd[1]);
	dup2(files.fd[0], 0);
	close(files.fd[0]);
	return (ft_open_files(NULL, av[ac - 1]));
}
