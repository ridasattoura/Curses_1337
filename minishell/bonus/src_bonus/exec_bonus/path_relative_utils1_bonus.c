/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_relative_utils1_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 07:37:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:45 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*resolve_command_path(char *command, char **path)
{
	char	*result;

	if (!command || *command == '\0')
		return (NULL);
	result = check_absolute_path(command);
	if (result)
		return (result);
	return (search_in_path(command, path));
}

int	check_directory_error(char *cmnd, int *exit_status)
{
	struct stat	st;

	if (stat(cmnd, &st) == 0 && S_ISDIR(st.st_mode))
	{
		perror("command is a directory");
		*exit_status = 126;
		return (1);
	}
	return (0);
}

void	print_command_not_found(char *cmnd, int *exit_status)
{
	ft_putstr_fd("minishell: command not found: ", 2);
	ft_putstr_fd(cmnd, 2);
	ft_putstr_fd("\n", 2);
	*exit_status = 127;
}

char	*ft_create_path(char *cmnd, char **envp, int *exit_status)
{
	char	**path;
	char	*resolved_path;

	if (check_directory_error(cmnd, exit_status))
		return (NULL);
	resolved_path = check_absolute_path(cmnd);
	if (resolved_path)
		return (resolved_path);
	path = ft_get_path(envp);
	if (!path)
	{
		print_command_not_found(cmnd, exit_status);
		return (NULL);
	}
	resolved_path = search_in_path(cmnd, path);
	ft_free(path);
	if (resolved_path)
		return (resolved_path);
	else
	{
		print_command_not_found(cmnd, exit_status);
		return (NULL);
	}
}
