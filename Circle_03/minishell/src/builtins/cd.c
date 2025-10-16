/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:23:30 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 14:47:46 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*simple_operation(char *value, char *re)
{
	free(value);
	return (ft_strdup(re));
}

void	ft_cd(t_shell *shell)
{
	char	re[1024];
	t_env	*temp;
	char	*target_dir;

	if (!shell->ast_root->full_cmd->cmd[1])
	{
		temp = shell->envp_list;
		target_dir = NULL;
		while (temp)
		{
			if (ft_strncmp("HOME", temp->variable, 4) == 0)
			{
				target_dir = temp->value;
				break;
			}
			temp = temp->next;
		}
		if (!target_dir)
		{
			ft_putstr_fd("cd: HOME not set\n", 2);
			shell->exit_status = 1;
			return ;
		}
	}
	else
		target_dir = shell->ast_root->full_cmd->cmd[1];

	getcwd(re, 1024);
	temp = shell->envp_list;
	while (temp)
	{
		if (ft_strncmp("OLDPWD", temp->variable, 6) == 0)
			temp->value = simple_operation(temp->value, re);
		temp = temp->next;
	}
	if (chdir(target_dir) != 0)
	{
		perror("cd");
		shell->exit_status = 1;
		return ;
	}
	getcwd(re, 1024);
	temp = shell->envp_list;
	while (temp)
	{
		if (ft_strncmp("PWD", temp->variable, 3) == 0)
			temp->value = simple_operation(temp->value, re);
		temp = temp->next;
	}
	shell->exit_status = 0;
}
