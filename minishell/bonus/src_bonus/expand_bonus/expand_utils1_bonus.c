/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/27 05:54:57 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:03 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	set_flag(char *str, int *i, t_quote *flag)
{
	if (*flag == NO_QUOTE && str[*i] == 39)
	{
		str[*i] = 1;
		*flag = IN_S_QUOTE;
		return (true);
	}
	else if (*flag == NO_QUOTE && str[*i] == 34)
	{
		str[*i] = 2;
		*flag = IN_D_QUOTE;
		return (true);
	}
	else if (str[*i] == 39 && *flag == IN_S_QUOTE)
	{
		str[*i] = 1;
		*flag = NO_QUOTE;
		return (true);
	}
	else if (str[*i] == 34 && *flag == IN_D_QUOTE)
	{
		str[*i] = 2;
		*flag = NO_QUOTE;
		return (true);
	}
	return (false);
}

t_env	*get_variable_envp(t_env *envp_list, char *extract)
{
	t_env	*temp;
	int		len;

	temp = envp_list;
	while (temp)
	{
		len = ft_strlen(temp->variable);
		if (!ft_strncmp(temp->variable, extract, len)
			&& len == (int)ft_strlen(extract))
			return (temp);
		temp = temp->next;
	}
	return (NULL);
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
