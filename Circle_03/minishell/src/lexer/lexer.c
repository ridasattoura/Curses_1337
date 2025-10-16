/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:02:44 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/06 16:14:55 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token	*create_list(char *line)
{
	t_token			*head;
	int				i;
	int				err;
	char			*lexeme;

	i = 0;
	err = 0;
	head = NULL;
	while (line[i])
	{
		skip_whitespaces(line, &i);
		if (!line[i])
			break ;
		if (is_operator_start(line + i))
			add_token(&head, new_token(get_token_type(&line[i]),
					grab_operator(line, &i)));
		else
		{
			lexeme = grab_word(line, &i, &err);
			if (!lexeme)
				return (ft_print_error(10), NULL);
			add_token(&head, new_token(COMMAND, lexeme));
		}
	}
	return (head);
}
