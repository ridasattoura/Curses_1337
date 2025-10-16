/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_path_cmnds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:11:02 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 17:59:03 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*resolve_command_path(char *command, char **path)
{
	int		j;
	char	**tmp;
	char	*tmp_path;
	char	*part_one;

	if (!command || *command == '\0')
		return (NULL);
	j = 0;
	while (path[j])
	{
		tmp = ft_split(command, ' ');
		part_one = ft_strjoin(path[j], "/");
		tmp_path = ft_strjoin(part_one, tmp[0]);
		free(part_one);
		if (access(tmp_path, F_OK) == 0)
			return (ft_free(tmp), tmp_path);
		free(tmp_path);
		tmp_path = ft_strdup(tmp[0]);
		ft_free(tmp);
		if (access(tmp_path, F_OK) == 0)
			return (tmp_path);
		free(tmp_path);
		j++;
	}
	return (NULL);
}

char	**ft_get_cmnds(char **av, int ac, char **path, int index)
{
	int		i;
	char	**cmnds;
	char	*resolved_path;

	cmnds = malloc(sizeof(char *) * (ac - index));
	if (!cmnds)
		return (NULL);
	i = 0;
	while (i + index < ac - 1)
	{
		resolved_path = resolve_command_path(av[i + index], path);
		if (resolved_path)
			cmnds[i] = resolved_path;
		else
		{
			cmnds[i] = ft_strdup(av[i + index]);
			perror("command not found");
		}
		i++;
	}
	cmnds[i] = NULL;
	return (cmnds);
}
