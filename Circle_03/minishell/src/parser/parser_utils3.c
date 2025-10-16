/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:47:07 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/02 22:37:58 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	is_logic_token(t_token *tok)
{
	return (tok && (tok->type == OR || tok->type == AND));
}

bool	is_cmd_or_redir(t_token *tok)
{
	return (tok && (tok->type == COMMAND || tok->type == REDIRECT_IN
			|| tok->type == REDIRECT_OUT || tok->type == APPEND
			|| tok->type == HEREDOC));
}

t_token	*find_matching_close(t_token *open)
{
	t_token	*scan;
	int		depth;

	depth = 1;
	scan = open->next;
	while (scan)
	{
		if (scan->type == parenthesis_open)
			depth++;
		else if (scan->type == parenthesis_close)
			depth--;
		if (depth == 0)
			return (scan);
		scan = scan->next;
	}
	return (NULL);
}

void	ft_print_error(int error)
{
	if (error == 0)
		printf(RED ERR0 RESET);
	else if (error == 1)
		printf(RED SYNTAX ERR1 RESET);
	else if (error == 2)
		printf(RED SYNTAX ERR2 RESET);
	else if (error == 3)
		printf(RED SYNTAX ERR3 RESET);
	else if (error == 4)
		printf(RED SYNTAX ERR4 RESET);
	else if (error == 5)
		printf(RED SYNTAX ERR5 RESET);
	else if (error == 6)
		printf(RED SYNTAX ERR6 RESET);
	else if (error == 7)
		printf(RED SYNTAX ERR7 RESET);
	else if (error == 8)
		printf(RED SYNTAX ERR8 RESET);
	else if (error == 9)
		printf(RED SYNTAX ERR9 RESET);
	else if (error == 10)
		printf(RED SYNTAX ERR10 RESET);
	else if (error == 11)
		printf(RED ERR11 RESET);
}

bool	check_paren_logic(t_token *start, t_token *end)
{
	t_token	*cur;
	t_token	*close;

	cur = start;
	while (cur && cur != end)
	{
		if (cur->type == parenthesis_open)
		{
			close = find_matching_close(cur);
			if (is_cmd_or_redir(cur->prev) || is_cmd_or_redir(close->next))
				return (ft_print_error(1), false);
			if (!is_logic_token(cur->prev) && !is_logic_token(close->next))
				return (ft_print_error(2), false);
			if (!check_paren_logic(cur->next, close))
				return (false);
		}
		cur = cur->next;
	}
	return (true);
}
