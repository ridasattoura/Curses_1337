/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_relative.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/13 16:06:12 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 00:19:44 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static void	ft_free(char **array)
{
	int	i;

	i = 0;
	if (!array)
		return;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

static char	**ft_get_path(char **env)
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

static char	*resolve_command_path(char *command, char **path)
{
	int		j;
	char	*tmp;
	char	*tmp_path;
	char	*part_one;

	
	if (!command || *command == '\0')
		return (NULL);
	j = 0;
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
	else
	{
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
	}
	
	return (NULL);
}

char	*ft_create_path(char *cmnd, char **envp, int *exit_status)
{
	char		**path;
	char		*resolved_path;
	struct stat	st;

	if (stat(cmnd, &st) == 0 && S_ISDIR(st.st_mode))
	{
		perror("command is a directory");
		*exit_status = 126;
		return (NULL);
	}
	path = ft_get_path(envp);
	if (!path)
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmnd, 2);
		ft_putstr_fd("\n", 2);
		*exit_status = 127;
		return (NULL);
	}
	resolved_path = resolve_command_path(cmnd, path);
	ft_free(path);
	if (resolved_path)
		return (resolved_path);
	else
	{
		ft_putstr_fd("minishell: command not found: ", 2);
		ft_putstr_fd(cmnd, 2);
		ft_putstr_fd("\n", 2);
		*exit_status = 127;
		return (NULL);
	}
}
// static char	*resolve_command_path(char *command, char **path)
// {
// 	int		j;
// 	char	**tmp;
// 	char	*tmp_path;
// 	char	*part_one;

// 	if (!command || *command == '\0')
// 		return (NULL);
// 	j = 0;
// 	while (path[j])
// 	{
// 		tmp = ft_split(command, ' ');
// 		part_one = ft_strjoin(path[j], "/");
// 		tmp_path = ft_strjoin(part_one, tmp[0]);
// 		free(part_one);
// 		if (access(tmp_path, F_OK) == 0)
// 			return (ft_free(tmp), tmp_path);
// 		free(tmp_path);
// 		tmp_path = ft_strdup(tmp[0]);
// 		ft_free(tmp);
// 		if (access(tmp_path, F_OK) == 0)
// 			return (tmp_path);
// 		free(tmp_path);
// 		j++;
// 	}
// 	return (NULL);
// }

// char	*ft_create_path(char *cmnd, char **envp)
// {
// 	char	**path;
// 	char	*resolved_path;

// 	path = ft_get_path(envp);
// 	if (!path)
// 		return (NULL);
// 	resolved_path = resolve_command_path(cmnd, path);
// 	if (resolved_path)
// 		return (resolved_path);
// 	else
// 	{
// 		perror("command not found");
// 		return (NULL);
// 	}
// }
