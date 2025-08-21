/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:40:23 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 15:19:56 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	print_env_list(t_shell *shell)
{
	t_env	*head;

	head = shell->envp_list;
	while (head != NULL)
	{
		if (head->is_export == true)
		{
			printf("%s=%s", head->variable, head->value);
			printf("\n");
		}
		head = head->next;
	}
	shell->exit_status = 0;
}
