/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils5_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:18:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:22:36 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	get_precedence(t_token_type type)
{
	if (type == OR)
		return (1);
	else if (type == AND)
		return (2);
	else if (type == PIPE)
		return (3);
	return (10);
}

bool	is_parenthesis(t_token_type type)
{
	return (type == parenthesis_open || type == parenthesis_close);
}

bool	is_ast_operator(t_token_type type)
{
	return (type == OR || type == AND || type == PIPE);
}

bool	is_redirection(t_token_type type)
{
	return (type == REDIRECT_IN || type == REDIRECT_OUT || type == APPEND
		|| type == HEREDOC);
}

bool	redirection_handle(t_token **list)
{
	t_token	*ptr;
	t_token	*tmp;

	ptr = *list;
	while (ptr)
	{
		if (is_redirection(ptr->type))
		{
			if (!ptr->next || ptr->next->type != COMMAND)
				return (ft_print_error(9), false);
			else
			{
				ptr->next->type = ptr->type;
				tmp = ptr;
				ptr = ptr->next;
				remove_node(list, tmp);
			}
		}
		ptr = ptr->next;
	}
	return (true);
}
