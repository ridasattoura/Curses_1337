/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 05:36:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 03:04:21 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_expand(int *i, t_quote *flag, int *start, char **expanded)
{
	*i = 0;
	*expanded = ft_strdup("");
	*start = 0;
	*flag = NO_QUOTE;
}

void	exchange_quotes(t_token *cmd)
{
	t_quote	flag;
	int		i;

	i = 0;
	flag = NO_QUOTE;
	while (cmd->next)
		cmd = cmd->next;
	while (cmd->value[i])
	{
		if ((cmd->value[i] == '\'' || cmd->value[i] == '"'))
			set_flag(cmd->value, &i, &flag);
		i++;
	}
}