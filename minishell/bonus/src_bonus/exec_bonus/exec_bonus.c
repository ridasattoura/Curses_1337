/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 23:56:38 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:32 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	exec(t_shell *shell, int flag)
{
	if (shell->ast_root == NULL)
		return ;
	if (shell->ast_root->type == PIPE)
		ft_pipe(shell, flag);
	else if (shell->ast_root->type == COMMAND)
		ft_command(shell, flag);
	else if (shell->ast_root->type == AND)
		ft_and(shell);
	else if (shell->ast_root->type == OR)
		ft_or(shell);
}
