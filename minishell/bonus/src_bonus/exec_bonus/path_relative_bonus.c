/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_relative_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:06:12 by risattou          #+#    #+#             */
/*   Updated: 2025/07/19 08:53:43 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return ;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

char	**ft_get_path(char **env)
{
	int	i;

	i = 0;
	if (!env || !*env)
		return (NULL);
	while (env[i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
			break ;
		i++;
	}
	if (!env[i])
		return (NULL);
	env[i] += 5;
	return (ft_split(env[i], ':'));
}

char	*check_absolute_path(char *command)
{
	if (command[0] == '.' || command[0] == '/')
	{
		if (access(command, F_OK) == 0)
		{
			if (access(command, X_OK) == 0)
				return (ft_strdup(command));
			else
				return (NULL);
		}
		else
			return (NULL);
	}
	return (NULL);
}

char	*search_in_path(char *command, char **path)
{
	int		j;
	char	*tmp;
	char	*tmp_path;
	char	*part_one;

	j = 0;
	while (path[j])
	{
		tmp = ft_strdup(command);
		part_one = ft_strjoin(path[j], "/");
		tmp_path = ft_strjoin(part_one, tmp);
		free(part_one);
		if (access(tmp_path, F_OK) == 0)
			return (free(tmp), tmp_path);
		free(tmp_path);
		free(tmp);
		j++;
	}
	return (NULL);
}
