/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 11:28:37 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:52:55 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static void	print_echo(char **args)
{
	int	i;

	i = 0;
	while (args[i] != NULL)
	{
		printf("%s", args[i]);
		i++;
		if (args[i] != NULL)
			printf(" ");
	}
}

static int	filter(char *flag)
{
	int	i;

	i = 0;
	if (flag[i] == '-')
	{
		i++;
		while (flag[i] == 'n')
			i++;
		if (flag[i] == '\0')
			return (1);
	}
	return (0);
}

void	ft_echo(t_shell *shell)
{
	int		i;
	char	**cmd;
	int		n_flag;

	cmd = shell->ast_root->full_cmd->cmd;
	i = 1;
	n_flag = 0;
	while (cmd[i] && filter(cmd[i]))
	{
		n_flag = 1;
		i++;
	}
	print_echo(cmd + i);
	if (!n_flag)
		printf("\n");
	shell->exit_status = 0;
}
