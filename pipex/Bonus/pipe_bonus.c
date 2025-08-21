/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:12:49 by risattou          #+#    #+#             */
/*   Updated: 2025/03/21 14:29:39 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_child_process(t_files files, char **cmnds, char **env, char **av)
{
	char	**args;

	args = ft_split_qouts(av[files.index + files.count], ' ');
	if (!args)
	{
		perror("faild split cmnd ");
		return (ft_close(files, NULL, cmnds), exit(1));
	}
	if (files.index == 0 && files.fdin == -1 && files.count == 2)
		return (ft_close(files, args, cmnds), exit(1));
	if (cmnds[files.index + 1] == NULL && files.fdout == -1)
		return (ft_close(files, args, cmnds), exit(1));
	else if (cmnds[files.index + 1] == NULL && files.fdout != -1)
		dup2(files.fdout, 1);
	else
		dup2(files.fd[1], 1);
	ft_close(files, NULL, NULL);
	if (execve(cmnds[files.index], args, env) == -1)
	{
		perror("faild execve");
		return (ft_close(files, args, cmnds), exit(1));
	}
}

int	ft_parent_process(t_files files, int id)
{
	close(files.fd[1]);
	dup2(files.fd[0], 0);
	close(files.fd[0]);
	return (id);
}
