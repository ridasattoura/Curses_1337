/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:49:13 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 07:18:58 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_context_stucture(t_context *context, t_token *list)
{
	context->precedence = 0;
	context->depth = 0;
	context->lowest_precedence = 10;
	context->subshell = false;
	context->list = list;
}

t_ast	*branch_root(t_token *branch, t_token *list)
{
	t_ast	*ptr;
	t_token	*next;

	ptr = new_tree_node(branch->type, NULL);
	if (!ptr)
		return (NULL);
	next = branch->next;
	detach_node(branch, 1);
	ptr->left = create_tree(list);
	if (!ptr->left)
		return (free(ptr), NULL);
	ptr->right = create_tree(next);
	if (!ptr->right)
		return (free_tree(ptr->left), free(ptr), NULL);
	return (ptr);
}

t_ast	*commands(t_token *list)
{
	t_ast		*ptr;
	t_full_cmd	*cmd;

	cmd = commands_handle(&list, NULL);
	if (!cmd)
		return (NULL);
	ptr = new_tree_node(COMMAND, cmd);
	if (!ptr)
		return (NULL);
	free_list(list);
	return (ptr);
}

t_ast	*create_tree(t_token *list)
{
	t_token		*branch;
	t_context	context;
	t_ast		*ptr;

	ptr = NULL;
	init_context_stucture(&context, list);
	branch = find_branch_root(&context);
	if (branch)
		ptr = branch_root(branch, list);
	else
		ptr = commands(list);
	return (ptr);
}
