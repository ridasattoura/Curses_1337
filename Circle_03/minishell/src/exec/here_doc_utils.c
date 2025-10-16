/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:55:11 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/08 20:07:13 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	her_her(t_ast *ast_root, int *exit_status)
{
	if (ast_root == NULL || *exit_status == -2)
		return ;
	if (ast_root->type == COMMAND)
	{
		ast_root->full_cmd->fd = ft_here_doc_(ast_root->full_cmd->red_in);
		if (ast_root->full_cmd->fd == -2)
		{
			*exit_status = -2;
			return ;
		}
	}
	her_her(ast_root->left, exit_status);
	her_her(ast_root->right, exit_status);
}
