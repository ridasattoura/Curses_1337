/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_and_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:33:37 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:41 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	ft_or(t_shell *shell)
{
	t_ast	*tete;

	tete = shell->ast_root;
	shell->ast_root = tete->left;
	exec(shell, 0);
	if (shell->exit_status != 0)
	{
		shell->ast_root = tete->right;
		exec(shell, 0);
	}
	shell->ast_root = tete;
}

void	ft_and(t_shell *shell)
{
	t_ast	*tete;

	tete = shell->ast_root;
	shell->ast_root = tete->left;
	exec(shell, 0);
	if (shell->exit_status == 0)
	{
		shell->ast_root = tete->right;
		exec(shell, 0);
	}
	shell->ast_root = tete;
}
