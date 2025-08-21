/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:34:23 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:28:45 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	consecutive_operators(t_token *head)
{
	t_token	*prev;

	prev = NULL;
	if (head->type == PIPE)
		return (ft_print_error(6), false);
	while (head)
	{
		if (head->type == PIPE && prev && head->prev->type == PIPE)
			return (ft_print_error(7), false);
		prev = head;
		head = head->next;
	}
	if (prev && prev->type == PIPE)
		return (ft_print_error(8), false);
	return (true);
}

t_token	*find_branch_root(t_context *context)
{
	t_token	*branch_root;

	branch_root = NULL;
	if (!context->list)
		return (NULL);
	while (context->list)
	{
		if (context->list->type == PIPE && context->depth == 0)
		{
			if (3 < context->lowest_precedence
				|| (context->lowest_precedence == 3))
			{
				context->lowest_precedence = 3;
				branch_root = context->list;
			}
		}
		context->list = context->list->next;
	}
	return (branch_root);
}

void	free_list(t_token *list)
{
	t_token	*temp;

	while (list)
	{
		temp = list;
		list = list->next;
		temp->next = NULL;
		temp->prev = NULL;
		free(temp->value);
		free(temp);
	}
}

void	init_trans(int *i, int *len)
{
	*i = 0;
	*len = 0;
}
