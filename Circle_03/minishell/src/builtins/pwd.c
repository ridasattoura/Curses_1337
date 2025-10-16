/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 16:23:13 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 16:13:02 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_pwd(t_shell *shell)
{
	t_env	*temp;
	char	re[1024];

	temp = shell->envp_list;
	getcwd(re, 1024);
	if(re[0] != 0)
	{
		printf("%s\n",re);
		return ;
	}
	while (temp->next)
	{
		if (ft_strncmp(temp->variable, "PWD", 4) == 0)
		{
			printf("%s\n", temp->value);
			shell->exit_status = 0;
			return ;
		}
		temp = temp->next;
	}
	shell->exit_status = 1;
	return ;
}
