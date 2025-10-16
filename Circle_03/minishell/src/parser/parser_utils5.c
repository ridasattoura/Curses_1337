/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils5.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 22:18:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/02 22:38:53 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minishell.h>

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
