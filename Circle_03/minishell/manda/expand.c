/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ader <ader@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:25:36 by mohchaib          #+#    #+#             */
/*   Updated: 2025/06/30 03:57:51 by ader             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	expand_token(char *string, char **expanded,
	t_quote	*flag, t_env *envp_list)
{
	int		i;
	char	*tmp;
	char	*var;

	i = 0;
	while (string[i])
	{
		if ((string[i] == '\'' || string[i] == '"'))
			if (set_flag(string, &i, flag))
				continue;
		if (string[i] == '$' && *flag != IN_S_QUOTE)
		{
			var = expand_variable(string, &i, envp_list);
			if (!var)
				continue ;
			tmp = *expanded;
			*expanded = ft_strjoin(*expanded, var);
			free_two(tmp, var);
			i++;
		}
		else
			*expanded = no_expand(string[i++], *expanded);
	}
}

t_token	*ft_expand(t_token *cmd, t_env *envp_list)
{
	t_quote	flag;
	t_token	*temp;
	char	*expanded;

	temp = cmd;
	while (cmd)
	{
		flag = NO_QUOTE;
		expanded = ft_strdup("");
		if (cmd->type == HEREDOC)
		{
			cmd->type = expand_check(cmd->value);
			if (cmd->type == EXPAND_HERE_DOC)
				cmd = ft_here_doc_expand(cmd);
			continue ;
		}
		if (!expanded)
			return (NULL);
		wirte(1,"ici0\n",5);
		expand_token(cmd->value, &expanded, &flag, envp_list);
		free(cmd->value);
		cmd->value = expanded;
		cmd = cmd->next;
	}
	return (temp);
}

t_full_cmd	*full_expand(t_full_cmd *cmd, t_env *envp_list)
{
	t_full_cmd	*expanded;

	expanded = cmd;
	expanded->cmd = NULL;
	// expanded->red_in = ft_expand(cmd->red_in, envp_list);
	// expanded->red_out = ft_expand(cmd->red_out, envp_list);
	expanded->args = ft_expand(cmd->args, envp_list);
	if ((cmd->red_in && !expanded->red_in)
		|| (cmd->red_out && !expanded->red_out)
		|| (cmd->args && !expanded->args))
		return (ft_print_error(0), NULL);
	return (expanded);
}
