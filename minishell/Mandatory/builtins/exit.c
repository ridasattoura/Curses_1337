/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 21:04:25 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 07:28:13 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strncpy(char *dest, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (src[i] && i < n)
	{
		dest[i] = src[i];
		i++;
	}
	while (i < n)
	{
		dest[i] = '\0';
		i++;
	}
	return (dest);
}

char	*ft_strtrim_(const char *str)
{
	int		start;
	int		end;
	char	*trimmed;

	start = 0;
	end = ft_strlen(str);
	if (!str)
		return (NULL);
	while (str[start] && is_whitespace(str[start]))
		start++;
	while (end > start && is_whitespace(str[end - 1]))
		end--;
	trimmed = malloc(end - start + 1);
	if (!trimmed)
		return (NULL);
	ft_strncpy(trimmed, str + start, end - start);
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
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	validate_exit_args(t_shell *shell, char **trimmed_arg)
{
	if (!shell->ast_root->full_cmd->cmd[1])
		return (shell->exit_status);
	*trimmed_arg = ft_strtrim_(shell->ast_root->full_cmd->cmd[1]);
	if (!*trimmed_arg || (*trimmed_arg)[0] == '\0' || !is_numeric(*trimmed_arg))
	{
		free(*trimmed_arg);
		*trimmed_arg = NULL;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(shell->ast_root->full_cmd->cmd[1], 2);
		ft_putstr_fd(": numeric argument required\n", 2);
		return (255);
	}
	if (shell->ast_root->full_cmd->cmd[2])
	{
		ft_putstr_fd("minishell: exit: too many arguments\n", 2);
		shell->exit_status = 1;
		free(*trimmed_arg);
		*trimmed_arg = NULL;
		return (-1);
	}
	return (ft_atoi(*trimmed_arg) % 256);
}

void	ft_exit(t_shell *shell)
{
	int		num;
	char	*trimmed_arg;

	trimmed_arg = NULL;
	num = validate_exit_args(shell, &trimmed_arg);
	if (num == -1)
	{
		return ;
	}
	if (trimmed_arg)
		free(trimmed_arg);
	cleanup(shell, NULL);
	exit(num);
}
