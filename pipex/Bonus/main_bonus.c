/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:22:59 by risattou          #+#    #+#             */
/*   Updated: 2025/03/22 01:45:58 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

int	execute(char **cmnds, char **env, char **av, t_files files)
{
	int	id;
	int	status;
	int	last_id;

	files.index = 0;
	last_id = 0;
	while (cmnds[files.index] != NULL)
	{
		if (pipe(files.fd) == -1)
			return (perror("faild pipe"), 1);
		id = fork();
		if (id == 0)
			ft_child_process(files, cmnds, env, av);
		else if (id > 0)
			last_id = ft_parent_process(files, id);
		files.index++;
	}
	waitpid(last_id, &status, 0);
	while (wait(NULL) > 0)
		;
	close(0);
	return (WEXITSTATUS(status));
}

int	main(int ac, char **av, char **env)
{
	char	**path;
	t_files	files;
	char	**cmnds;

	if (ac < 5)
		return (ft_putstr_fd("Error syntaxe:./pipex file1 cmd1 cmd2 ... file2\n",
				1), 1);
	path = ft_get_path(env);
	if (!path)
		return (ft_putstr_fd("failed get path\n", 1), 1);
	cmnds = NULL;
	if (ft_strncmp(av[1], "here_doc", 8) == 0 && ac == 6)
		files = ft_here_doc(av, ac);
	else
		files = ft_open_files(av[1], av[ac - 1]);
	if (files.fdin == -1 && files.fdout == -1)
		return (ft_close(files, path, NULL), 1);
	cmnds = ft_get_cmnds(av, ac, path, files.count);
	if (!cmnds)
		return (ft_close(files, path, NULL), 1);
	ft_free(path);
	if (execute(cmnds, env, av, files) != 0)
		return (ft_close(files, cmnds, NULL), 1);
	return (ft_close(files, cmnds, NULL), 0);
}
