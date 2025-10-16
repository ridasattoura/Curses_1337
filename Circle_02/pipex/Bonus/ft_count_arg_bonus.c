/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_arg_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:51:11 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 21:40:27 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static void	handle_single_quote(const char *str, t_qouts *qouts)
{
	qouts->counds = 1;
	(qouts->index)++;
	while (str[qouts->index] != '\'' && str[qouts->index])
		(qouts->index)++;
	if (str[qouts->index] == '\'' && str[qouts->index])
	{
		(qouts->count)++;
		qouts->counds = 2;
	}
}

static void	handle_double_quote(const char *str, t_qouts *qouts)
{
	qouts->coundd = 1;
	(qouts->index)++;
	while (str[qouts->index] != '\"' && str[qouts->index])
		(qouts->index)++;
	if (str[qouts->index] == '\"' && str[qouts->index])
	{
		(qouts->count)++;
		qouts->coundd = 2;
	}
}

static void	handle_quotes(const char *str, t_qouts *qouts)
{
	if ((str[qouts->index] == '\'' && str[qouts->index + 1] == '\'')
		|| (str[qouts->index] == '\"' && str[qouts->index + 1] == '\"'))
		qouts->index += 2;
	if (str[qouts->index] == '\'' && str[qouts->index + 1] != '\'')
	{
		handle_single_quote(str, qouts);
	}
	else if (str[qouts->index] == '\"' && str[qouts->index + 1] != '\"')
	{
		handle_double_quote(str, qouts);
	}
}

int	skip_delimiters(const char *str, t_qouts *qouts, char c)
{
	while ((str[qouts->index] == c || str[qouts->index] == '\''
			|| str[qouts->index] == '\"') && str[qouts->index])
	{
		qouts->counds = 0;
		qouts->coundd = 0;
		handle_quotes(str, qouts);
		if (qouts->counds == 1 || qouts->coundd == 1)
			return (0);
		if (str[qouts->index] == '\0')
			break ;
		qouts->index++;
	}
	return (1);
}

void	count_words(const char *str, t_qouts *qouts, char c)
{
	if (!(str[qouts->index] == c || str[qouts->index] == '\''
			|| str[qouts->index] == '\"') && str[qouts->index])
		qouts->count++;
	while (!(str[qouts->index] == c || str[qouts->index] == '\''
			|| str[qouts->index] == '\"') && str[qouts->index])
		qouts->index++;
}
