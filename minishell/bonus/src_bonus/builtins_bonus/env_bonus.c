/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:40:23 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:52:57 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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
