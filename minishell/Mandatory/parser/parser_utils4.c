/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils4.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:13:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/19 07:25:34 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

bool	syntax_error(t_token *list)
{
	if (!consecutive_operators(list))
		return (false);
	return (true);
}

char	*token_type_str(t_token_type type)
{
	if (type == COMMAND)
		return ("COMMAND");
	if (type == PIPE)
		return ("PIPE");
	if (type == REDIRECT_IN)
		return ("REDIRECT_IN");
	if (type == REDIRECT_OUT)
		return ("REDIRECT_OUT");
	if (type == APPEND)
		return ("APPEND");
	if (type == HEREDOC)
		return ("HEREDOC");
	if (type == EXPAND_HERE_DOC)
		return ("EXPAND_HERE_DOC");
	if (type == AMBIGUOUS)
		return ("AMBIGUOUS");
	return ("UNKNOWN");
}

void	remove_node(t_token **list, t_token *node)
{
	t_token	*next;
	t_token	*prev;

	next = node->next;
	prev = node->prev;
	if (prev)
		prev->next = next;
	else
		*list = next;
	if (next)
		next->prev = prev;
	free(node->value);
	free(node);
}

t_ast	*new_tree_node(t_token_type type, t_full_cmd *full_cmd)
{
	t_ast	*node;

	node = malloc(sizeof(t_ast));
	if (!node)
		return (NULL);
	node->full_cmd = full_cmd;
	node->type = type;
	node->left = NULL;
	node->right = NULL;
	return (node);
}
