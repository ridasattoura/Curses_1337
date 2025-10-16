/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/09 12:12:29 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 15:29:07 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_ambiguous(t_token *file)
{
	while (file != NULL)
	{
		if (file->type == AMBIGUOUS)
			return (-1);
		file = file->next;
	}
	return (1);
}

char	*expand_variable_(char *str, int *i, t_env *envp_list)
{
	int		start;
	int		len;
	char	*name;
	t_env	*var;

	(*i)++;
	start = *i;
	len = 0;
	while (str[start + len] && str[start + len] != '$' && str[start
		+ len] != '?' && str[start + len] != '"' && str[start + len] != '\''
		&& !is_whitespace(str[start + len]))
		len++;
	if (len == 0)
		return (NULL);
	name = ft_substr(str, start, len);
	if (!name)
		return (NULL);
	var = get_variable_envp(envp_list, name);
	free(name);
	*i = start + len;
	if (!var || !var->value)
		return (ft_strdup(""));
	return (ft_strdup(var->value));
}

void	code_handle2(int *i, char **expanded, char *cmd, int exit_status)
{
	char	*tmp;
	char	*var;
	int		flag;

	var = NULL;
	flag = 0;
	if (cmd[(*i) + 1] == '?')
	{
		flag = 1;
		var = ft_itoa(exit_status);
		(*i) += 2;
	}
	else if (cmd[(*i) + 1] == '0')
	{
		flag = 1;
		var = ft_strdup("./minishell");
		(*i) += 2;
	}
	if (flag)
	{
		tmp = *expanded;
		*expanded = ft_strjoin(*expanded, var);
		free_two(tmp, var);
	}
}

void	core_handling_(int *i, char **expanded, char *line, t_env *envp_list)
{
	char	*tmp;
	char	*var;

	var = expand_variable_(line, i, envp_list);
	if (!var)
		return ;
	tmp = *expanded;
	*expanded = ft_strjoin(*expanded, var);
	free_two(tmp, var);
}

void	check_availabel(t_env *envp, char *line, char **expanded,
		int exit_status)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '$')
		{
			code_handle2(&i, expanded, line, exit_status);
			core_handling_(&i, expanded, line, envp);
		}
		else
			*expanded = no_expand(line[i++], *expanded);
	}
}
