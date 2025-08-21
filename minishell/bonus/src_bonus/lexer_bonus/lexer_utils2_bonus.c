/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 13:42:56 by amn               #+#    #+#             */
/*   Updated: 2025/07/09 16:54:18 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	add_token(t_token **lst, t_token *new)
{
	t_token	*ptr;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		new->prev = NULL;
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
	new->prev = ptr;
}

void	skip_whitespaces(char *line, int *i)
{
	while (line[*i] && is_whitespace(line[*i]))
		(*i)++;
}

void	double_increment(int *i, int *len)
{
	(*i)++;
	(*len)++;
}

void	set_err(int *err)
{
	*err = 1;
}

char	*grab_word(char *line, int *i, int *err)
{
	char	*start;
	int		len;
	char	quote;

	len = 0;
	start = &line[*i];
	while (line[*i] && !is_whitespace(line[*i])
		&& !is_operator_start(&line[*i]))
	{
		if (line[*i] == '\'' || line[*i] == '"')
		{
			quote = line[(*i)];
			double_increment(i, &len);
			while (line[*i] && line[*i] != quote)
				double_increment(i, &len);
			if (!line[*i])
				return (set_err(err), NULL);
			double_increment(i, &len);
		}
		else
			double_increment(i, &len);
	}
	return (ft_substr(start, 0, len));
}
