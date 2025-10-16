/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:41:44 by mohchaib          #+#    #+#             */
/*   Updated: 2025/05/28 15:22:41 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_token_type expand_check(char *string)
{
    int i;

    i = 0;
    while (string[i])
    {
        if (string[i] == '"' || string[i] == '\'')
            return (EXPAND_HERE_DOC);
        i++;
    }
    return (HEREDOC);
}

void	remove_quotes_heredoc(char *string, char **expanded, t_quote	*flag)
{
	int		i;

	i = 0;
	while (string[i])
	{
		if ((string[i] == '\'' || string[i] == '"'))
        {
			if (set_flag(string, &i, flag))
				continue ;    
        }
		else
			*expanded = no_expand(string[i++], *expanded);
	}
}

t_token	*ft_here_doc_expand(t_token *cmd)
{
    t_quote	flag;
    char	*expanded;

    flag = NO_QUOTE;
    expanded = ft_strdup("");
    if (!expanded)
        return NULL;
    remove_quotes_heredoc(cmd->value, &expanded, &flag);
    free(cmd->value);
    cmd->value = expanded;
    return (cmd);
}
