/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   or_and.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/30 20:33:37 by risattou          #+#    #+#             */
/*   Updated: 2025/05/30 20:56:09 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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
