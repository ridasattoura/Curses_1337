/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:04:25 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 19:52:16 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <string.h>
#include <ctype.h>

// #include <stdlib.h>
// #include <stdio.h>

char	*ft_strtrim_(const char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = strlen(str);
	if (!str)
		return (NULL);
	while (str[start] && isspace(str[start]))
		start++;
	while (end > start && isspace(str[end - 1]))
		end--;
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	strncpy(trimmed, str + start, end - start);
	trimmed[end - start] = '\0';
	return (trimmed);
}

int	is_numeric(const char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (0);
	if (str[0] == '-' || str[0] == '+')
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(t_shell *shell)
{
	int		num;
	char	*trimmed_arg;

	num = shell->exit_status;
	if (shell->ast_root->full_cmd->cmd[1])
	{
		trimmed_arg = ft_strtrim_(shell->ast_root->full_cmd->cmd[1]);
		if (!trimmed_arg || trimmed_arg[0] == '\0' || !is_numeric(trimmed_arg))
		{
			free(trimmed_arg);
			num = 255;
			ft_putstr_fd("minishell: exit: ", 2);
			ft_putstr_fd(shell->ast_root->full_cmd->cmd[1], 2);
			ft_putstr_fd(": numeric argument required\n", 2);
		}
		if (shell->ast_root->full_cmd->cmd[2] && num != 255)
		{
			ft_putstr_fd("minishell: exit: too many arguments\n", 2);
			shell->exit_status = 1;
			return ;
		}
		else if (num == shell->exit_status)
		{
			num = ft_atoi(trimmed_arg) % 256;
			free(trimmed_arg);
		}
	}
	cleanup(shell, NULL);
	exit(num);
}
