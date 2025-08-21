/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils6_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:38:29 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:46 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell_bonus.h>

bool	check_parenthesis_logic(t_token *list)
{
	return (check_paren_logic(list, NULL));
}

bool	check_balanced_parentheses(t_token *head)
{
	int	depth;

	depth = 0;
	while (head)
	{
		if (head->type == parenthesis_open)
		{
			depth++;
			if (head->next && head->next->type == parenthesis_close)
				return (ft_print_error(3), false);
		}
		else if (head->type == parenthesis_close)
		{
			depth--;
			if (depth < 0)
				return (ft_print_error(4), false);
		}
		head = head->next;
	}
	if (depth != 0)
		return (ft_print_error(5), false);
	return (true);
}

void	detach_node(t_token *node, int remove)
{
	t_token	*prev;
	t_token	*next;

	if (!node)
		return ;
	prev = node->prev;
	if (prev)
		prev->next = NULL;
	next = node->next;
	if (next)
		next->prev = NULL;
	node->next = NULL;
	node->prev = NULL;
	if (remove)
		return (free(node->value), free(node));
}

void	trim_parenthesis(t_token **list)
{
	t_token	*ptr;

	ptr = (*list);
	(*list) = (*list)->next;
	detach_node(ptr, 1);
	ptr = (*list);
	while (ptr->next)
		ptr = ptr->next;
	detach_node(ptr, 1);
}

void	free_tree(t_ast *tree)
{
	if (!tree)
		return ;
	if (tree->full_cmd)
	{
		free_list(tree->full_cmd->red_in);
		free_list(tree->full_cmd->red_out);
		free_list(tree->full_cmd->args);
		free_matrix(tree->full_cmd->cmd);
		tree->full_cmd->red_in = NULL;
		tree->full_cmd->red_out = NULL;
		tree->full_cmd->args = NULL;
		tree->full_cmd->cmd = NULL;
		free(tree->full_cmd);
		tree->full_cmd = NULL;
	}
	free_tree(tree->left);
	free_tree(tree->right);
	free(tree);
}
