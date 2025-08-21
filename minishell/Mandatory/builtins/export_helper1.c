/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:12:42 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:44:02 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	core_check_var(t_env *temp, char *str)
{
	char	*tmp_str;

	if (!temp->value)
		temp->value = ft_strdup(str + ft_strlen_(str) + 2);
	else
	{
		tmp_str = temp->value;
		temp->value = ft_strjoin(tmp_str, str + ft_strlen_(str) + 2);
		free(tmp_str);
	}
}

int	ft_check_var(t_env *head, char *str)
{
	t_env	*temp;

	temp = head;
	while (temp != NULL)
	{
		if (ft_strncmp(temp->variable, str, ft_strlen_(str)) == 0
			&& temp->variable[ft_strlen_(str)] == '\0')
		{
			if (str[ft_strlen_(str)] == '=')
			{
				free(temp->value);
				temp->value = ft_strdup(str + 1 + ft_strlen_(str));
			}
			else if (str[ft_strlen_(str)] == '+' && str[ft_strlen_(str)
					+ 1] == '=')
				core_check_var(temp, str);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	create_var_check(t_env *temp, char *str)
{
	temp->variable = ft_strdup(str);
	temp->value = NULL;
	temp->is_export = false;
}

bool	init_shi(int *i, t_env **temp)
{
	*temp = malloc(sizeof(t_env));
	if (!temp)
		return (false);
	(*temp)->variable = NULL;
	(*temp)->value = NULL;
	(*temp)->is_export = false;
	(*temp)->next = NULL;
	*i = -1;
	return (true);
}

t_env	*ft_creat_var(char *str)
{
	t_env	*temp;
	int		i;

	if (!init_shi(&i, &temp))
		return (NULL);
	while (str[++i])
	{
		if (str[i] == '=' || (str[i] == '+' && str[i + 1] == '='))
		{
			temp->variable = ft_strdup_var(str, i);
			if (!temp->variable)
				return (free(temp), NULL);
			if (str[i] == '+')
				i++;
			temp->value = ft_strdup(str + i + 1);
			temp->is_export = true;
			return (temp);
		}
	}
	temp->variable = ft_strdup(str);
	if (!temp->variable)
		return (free(temp), NULL);
	temp->value = NULL;
	temp->is_export = false;
	return (temp);
}
