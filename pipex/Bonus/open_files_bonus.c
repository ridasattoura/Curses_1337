/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_files_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:12:19 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 22:13:18 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	ft_reset_files(t_files *files)
{
	files->fdin = -1;
	files->fdout = -1;
	files->fd[0] = -1;
	files->fd[1] = -1;
	files->index = 0;
	files->count = 0;
}

t_files	ft_open_files(char *file_in, char *file_out)
{
	t_files	files;

	ft_reset_files(&files);
	if (file_in == NULL)
	{
		files.count = 3;
		files.fdout = open(file_out, O_WRONLY | O_CREAT | O_APPEND, 0644);
	}
	else
	{
		files.fdin = open(file_in, O_RDONLY);
		if (0 > files.fdin)
			perror("open failed in");
		dup2(files.fdin, 0);
		files.count = 2;
		files.fdout = open(file_out, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	}
	if (0 > files.fdout)
		perror("open failed out");
	return (files);
}
