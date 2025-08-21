/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/18 01:55:27 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/06 16:04:04 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

t_env	*init_node(t_env *node)
{
	node = malloc(sizeof(t_env));
	if (!node)
		return (NULL);
	node->is_export = 0;
	node->next = NULL;
	node->value = NULL;
	node->variable = NULL;
	return (node);
}

char	*get_variable(char *line, int *j)
{
	char	*value;
	int		i;

	i = 0;
	value = NULL;
	while (line[i] && line[i] != '=')
		i++;
	if (line[i] == '=')
	{
		value = malloc(i + 1);
		if (!value)
			return (NULL);
		ft_strlcpy(value, line, i + 1);
		*j = i + 1;
	}
	return (value);
}

t_env	*envp_list(char **envp)
{
	t_env	*envp_list;
	t_env	*temp;
	int		i;
	int		j;

	i = 0;
	envp_list = NULL;
	while (envp[i])
	{
		temp = init_node(temp);
		if (!temp)
			return (free_envp(envp_list, envp), NULL);
		temp->variable = get_variable(envp[i], &j);
		if (!temp->variable)
			return (NULL);
		temp->value = ft_strdup(envp[i] + j);
		if (!temp->value)
			return (NULL);
		temp->is_export = 1;
		temp->next = envp_list;
		envp_list = temp;
		i++;
	}
	return (envp_list);
}

char	*get_from_envp(t_env *envp_list, char *extract)
{
	t_env	*temp;
	int		len;

	temp = envp_list;
	len = ft_strlen(extract);
	while (temp)
	{
		if (ft_strncmp(temp->variable, extract, len) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}
