/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:34:23 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:09:25 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	consecutive_operators(t_token *head)
{
	t_token	*prev;

	prev = NULL;
	if (is_ast_operator(head->type))
		return (ft_print_error(6), false);
	while (head)
	{
		if (head->type == parenthesis_open && head->next
			&& is_ast_operator(head->next->type))
			return (ft_print_error(7), false);
		if ((is_ast_operator(head->type)) && prev
			&& is_ast_operator(prev->type))
			return (ft_print_error(7), false);
		if (head->type == parenthesis_close && prev
			&& is_ast_operator(prev->type))
			return (ft_print_error(8), false);
		prev = head;
		head = head->next;
	}
	if (prev && is_ast_operator(prev->type))
		return (ft_print_error(8), false);
	return (true);
}

void	depth_check(t_token *token, int *depth, bool *subshell)
{
	if (token->type == parenthesis_open)
	{
		*subshell = true;
		(*depth)--;
	}
	else if (token->type == parenthesis_close)
		(*depth)++;
}

t_token	*find_branch_root(t_context *context)
{
	t_token	*branch_root;

	branch_root = NULL;
	if (!context->list)
		return (NULL);
	while (context->list)
	{
		depth_check(context->list, &context->depth, &context->subshell);
		if (is_ast_operator(context->list->type) && context->depth == 0)
		{
			context->precedence = get_precedence(context->list->type);
			if (context->precedence < context->lowest_precedence
				|| (context->lowest_precedence == 3
					&& context->precedence == 3))
			{
				context->lowest_precedence = context->precedence;
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
