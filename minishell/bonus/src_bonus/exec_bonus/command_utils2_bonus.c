/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 16:21:06 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:21:42 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ambiguous_handle_(t_shell *shell)
{
	if (shell->ast_root->full_cmd->ambigious == 1)
	{
		printf(ERR12);
		exit(1);
	}
}

void	close_2(int in, int out)
{
	close(in);
	close(out);
}
