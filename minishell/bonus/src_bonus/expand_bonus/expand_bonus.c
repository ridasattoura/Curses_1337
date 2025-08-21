/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:25:36 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/19 07:22:21 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	core(int *i, char **expanded, t_token *cmd, t_norm *mix)
{
	int		start;

	start = *i;
	code_handle(i, expanded, cmd, mix->exit_status);
	if (*i == start)
		core_handling(i, expanded, cmd, mix->envp_list);
}

void	expand_loopa(t_token *cmd, char **expanded, t_norm *mix)
{
	t_quote	flag;
	int		i;

	flag = NO_QUOTE;
	i = 0;
	while (cmd->value[i])
	{
		if (is_quote(cmd->value[i]) && set_flag(cmd->value, &i, &flag))
		{
			*expanded = no_expand(cmd->value[i++], *expanded);
			continue ;
		}
		if (cmd->value[i] == '$' && flag != IN_S_QUOTE)
			core(&i, expanded, cmd, mix);
		else
			*expanded = no_expand(cmd->value[i++], *expanded);
	}
}

void	expand_token(t_token *cmd, t_token **new, t_norm *mix)
{
	char	*expanded;
	bool	was_quoted;

	if (!cmd || !cmd->value)
		return ;
	expanded = ft_strdup("");
	was_quoted = (ft_strchr(cmd->value, '\'') || ft_strchr(cmd->value, '"'));
	expand_loopa(cmd, &expanded, mix);
	if (!was_quoted && expanded && ft_strchr(expanded, ' '))
		additional_handling(cmd, new, &expanded);
	else
		add_token(new, new_token(cmd->type, expanded));
	if (ft_strlen(expanded) == 0)
		*mix->is_ambigious = 1;
}

t_token	*ft_expand(t_token *list, t_env *envp_list,
	int exit_status, int *ambigious)
{
	t_token	*temp;
	t_token	*new;
	t_norm	mix;

	temp = list;
	new = NULL;
	init_exp(&mix, exit_status, ambigious, envp_list);
	while (list)
	{
		if (list->type == HEREDOC)
		{
			list->type = expand_check(list->value);
			add_token(&new, new_token(list->type, ft_strdup(list->value)));
			exchange_quotes(new);
			list = list->next;
			continue ;
		}
		expand_token(list, &new, &mix);
		list = list->next;
	}
	free_list(temp);
	return (new);
}

t_full_cmd	*full_expand(t_full_cmd *cmd, t_env *envp_list, int exit_status)
{
	t_full_cmd	*expanded;

	expanded = cmd;
	expanded->cmd = NULL;
	expanded->red_in = ft_expand(cmd->red_in, envp_list,
			exit_status, &cmd->ambigious);
	expanded->red_out = ft_expand(cmd->red_out, envp_list,
			exit_status, &cmd->ambigious);
	expanded->args = ft_expand(cmd->args, envp_list,
			exit_status, &cmd->ambigious);
	return (expanded);
}
