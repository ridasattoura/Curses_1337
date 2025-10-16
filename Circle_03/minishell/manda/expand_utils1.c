/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 05:54:57 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/06 20:52:20 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

bool	set_flag(char *str, int *i, t_quote *flag)
{
	if (*flag == NO_QUOTE && str[*i] == 39)
	{
		(*i)++;
		*flag = IN_S_QUOTE;
		return true;
	}
	else if (*flag == NO_QUOTE && str[*i] == 34)
	{
		(*i)++;
		*flag = IN_D_QUOTE;
		return true;
	}
	else if ((str[*i] == 39 && *flag == IN_S_QUOTE)
		|| (str[*i] == 34 && *flag == IN_D_QUOTE))
	{
		(*i)++;
		*flag = NO_QUOTE;
		return true;
	}
	return false;
}

t_env	*get_variable_envp(t_env *envp_list, char *extract)
{
	t_env	*temp;
	int		len;

	temp = envp_list;
	while (temp)
	{
		len = ft_strlen(temp->variable);
		if (!ft_strncmp(temp->variable, extract, len) && len == (int)ft_strlen(extract))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
}

char	*expand_variable(const char *str, int *i, t_env *envp_list)
{
	int		start;
	int		len;
	char	*name;
	t_env	*var;

	(*i)++;
	start = *i;
	len = 0;
	while (str[start + len] && str[start + len] != '$'
		&& str[start + len] != '"' && str[start + len] != '\'')
		len++;
	if (len == 0)
		return (NULL);
	name = ft_substr(str, start, len);
	if (!name)
		return (NULL);
	var = get_variable_envp(envp_list, name);
	free(name);
	*i = start + len -1 ;
	if (!var || !var->value)
		return (ft_strdup(""));
	return (ft_strdup(var->value));
}

char	*no_expand(char c, char *expanded)
{
	char	s[2];
	char	*tmp;

	s[0] = c;
	s[1] = '\0';
	tmp = expanded;
	expanded = ft_strjoin(expanded, s);
	free(tmp);
	return (expanded);
}

void	free_two(char *one, char *two)
{
	free(one);
	free(two);
}
