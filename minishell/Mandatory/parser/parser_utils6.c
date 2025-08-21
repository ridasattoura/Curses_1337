/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils6.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:38:29 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:31:32 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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

bool	only_whitespaces(char *str)
{
	int		i;
	bool	flag;

	i = 0;
	flag = true;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
			flag = false;
		i++;
	}
	return (flag);
}

int	inc_two(t_token	*args)
{
	int	len;

	len = 0;
	while (args)
	{
		len++;
		args = args->next;
	}
	return (len);
}
