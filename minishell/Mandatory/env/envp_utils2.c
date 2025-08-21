/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:34:34 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/06 22:38:43 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	free_envp(t_env *envp_list, char **envp)
{
	t_env	*temp;
	int		i;

	i = 0;
	while (envp_list)
	{
		temp = envp_list;
		envp_list = envp_list->next;
		if (temp->variable)
			free(temp->variable);
		if (temp->value)
			free(temp->value);
		free(temp);
	}
	if (envp != NULL)
	{
		while (envp[i] != NULL)
		{
			free(envp[i]);
			i++;
		}
		free(envp);
	}
}

int	count_export(t_env *envp_list)
{
	int	i;

	i = 0;
	while (envp_list)
	{
		if (envp_list->is_export == 1)
			i++;
		envp_list = envp_list->next;
	}
	return (i);
}

char	**get_env(t_env *envp_list)
{
	t_env	*temp;
	char	**env;
	int		i;

	i = 0;
	temp = envp_list;
	env = malloc((count_export(envp_list) + 1) * sizeof(char *));
	if (!env)
		return (NULL);
	while (temp)
	{
		if (temp->is_export == 1)
		{
			env[i] = ft_strjoin_(temp->variable, temp->value);
			if (!env[i])
			{
				free_matrix_(env, i - 1);
				return (0);
			}
			i++;
		}
		temp = temp->next;
	}
	env[i] = NULL;
	return (env);
}
