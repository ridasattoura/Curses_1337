/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 01:13:31 by amn               #+#    #+#             */
/*   Updated: 2025/05/28 16:09:36 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_operator_start(char *c)
{
	return (*c == '|' || *c == '&' || *c == '>' || *c == '<'
		|| *c == '(' || *c == ')');
}

t_token_type	get_token_type(char *s)
{
	if (s[0] == '>' && s[1] == '>')
		return (APPEND);
	if (s[0] == '<' && s[1] == '<')
		return (HEREDOC);
	if (s[0] == '<')
		return (REDIRECT_IN);
	if (s[0] == '>')
		return (REDIRECT_OUT);
	if (s[0] == '&' && s[1] == '&')
		return (AND);
	if (s[0] == '|' && s[1] == '|')
		return (OR);
	if (s[0] == '|')
		return (PIPE);
	if (s[0] == '(')
		return (parenthesis_open);
	if (s[0] == ')')
		return (parenthesis_close);
	return (COMMAND);
}

char	*grab_operator(char *s, int *i)
{
	int		len;
	char	*op;

	len = 1;
	if ((s[*i] == '|' && s[*i + 1] == '|') || (s[*i] == '&' && s[*i + 1] == '&')
		|| (s[*i] == '<' && s[*i + 1] == '<') || (s[*i] == '>' && s[*i
				+ 1] == '>'))
		len = 2;
	op = ft_substr(s, *i, len);
	*i += len;
	return (op);
}

int	is_whitespace(char c)
{
	return (c == 32 || (c >= 9 && c <= 13));
}

int	is_quote(char c)
{
	return (c == 34 || c == 39);
}
