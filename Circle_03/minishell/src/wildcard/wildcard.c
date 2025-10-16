/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 13:18:54 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/07 00:16:59 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	set_flag_remove(char *str, int *i, t_quote *flag)
{
	if (*flag == NO_QUOTE && str[*i] == 1)
	{
		*flag = IN_S_QUOTE;
		return (true);
	}
	else if (*flag == NO_QUOTE && str[*i] == 2)
	{
		*flag = IN_D_QUOTE;
		return (true);
	}
	else if (str[*i] == 1 && *flag == IN_S_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	else if (str[*i] == 2 && *flag == IN_D_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	return (false);
}

bool	has_unquoted_wildcard(char *str)
{
	t_quote	flag;
	int		i;

	i = 0;
	flag = NO_QUOTE;
	while (str[i])
	{
		if (set_flag_remove(str, &i, &flag))
		{
			i++;
			continue ;
		}
		if (str[i] == '*' && flag == NO_QUOTE)
			return (true);
		i++;
	}
	return (false);
}

t_token	*ft_wildcard(t_token *list)
{
	t_token	*expanded_list;
	t_token	*to_free;
	bool	found;

	to_free = list;
	expanded_list = NULL;
	while (list)
	{
		if (!has_unquoted_wildcard(list->value))
		{
			add_token(&expanded_list, new_token(list->type,
					ft_strdup(list->value)));
		}
		else
		{
			found = find_files(list, &expanded_list);
			if (!found)
				add_token(&expanded_list, new_token(list->type,
						ft_strdup(list->value)));
		}
		list = list->next;
	}
	free_list(to_free);
	return (expanded_list);
}

t_full_cmd	*full_wildcard(t_full_cmd *cmd)
{
	t_full_cmd	*expanded;

	expanded = cmd;
	expanded->cmd = NULL;
	expanded->red_in = ft_wildcard(cmd->red_in);
	expanded->red_out = ft_wildcard(cmd->red_out);
	expanded->args = ft_wildcard(cmd->args);
	if ((cmd->red_in && !expanded->red_in)
		|| (cmd->red_out && !expanded->red_out)
		|| (cmd->args && !expanded->args))
		return (ft_print_error(0), NULL);
	return (expanded);
}

char	*remove_first_value_quotes(char *str)
{
	t_quote	flag;
	char	*new;
	int		i;

	i = 0;
	flag = NO_QUOTE;
	new = ft_strdup("");
	while (str[i])
	{
		if (set_flag_remove(str, &i, &flag))
			i++;
		else
			new = no_expand(str[i++], new);
	}
	return (new);
}
