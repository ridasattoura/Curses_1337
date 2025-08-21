/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils3_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 05:36:05 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:07 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	init_exp(t_norm	*mix, int exit_status, int *ambigious, t_env *envp_list)
{
	mix->exit_status = exit_status;
	mix->is_ambigious = ambigious;
	mix->envp_list = envp_list;
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

void	code_handle(int *i, char **expanded, t_token *cmd, int exit_status)
{
	char	*tmp;
	char	*var;

	var = NULL;
	if (cmd->value[(*i) + 1] == '?')
	{
		var = ft_itoa(exit_status);
		(*i) += 2;
	}
	else if (cmd->value[(*i) + 1] == '0')
	{
		var = ft_strdup("./minishell");
		(*i) += 2;
	}
	if (var)
	{
		tmp = *expanded;
		*expanded = ft_strjoin(*expanded, var);
		free_two(tmp, var);
	}
}
