/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   here_doc_utils1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:29:11 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:56:15 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*loop_here(t_token	*current)
{
	t_token	*last_heredoc;

	while (current != NULL)
	{
		if (current->type == HEREDOC)
			last_heredoc = current;
		current = current->next;
	}
	return (last_heredoc);
}

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

void	close_heredoc_fds(t_ast *ast)
{
	if (!ast)
		return ;
	if (ast->type == COMMAND && ast->full_cmd && ast->full_cmd->fd != -1)
	{
		close(ast->full_cmd->fd);
		ast->full_cmd->fd = -1;
	}
	close_heredoc_fds(ast->left);
	close_heredoc_fds(ast->right);
}
