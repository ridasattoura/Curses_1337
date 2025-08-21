/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_utils1_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 12:24:31 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 17:03:14 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	init_cd(t_env **new_var, char *var_name, char *value)
{
	(*new_var) = malloc(sizeof(t_env));
	if (!(*new_var))
		return (false);
	(*new_var)->variable = ft_strdup(var_name);
	(*new_var)->value = ft_strdup(value);
	(*new_var)->is_export = true;
	(*new_var)->next = NULL;
	return (true);
}

void	update_env_variables(t_shell *shell, char *old_pwd, char *new_pwd)
{
	update_or_create_var(shell, "OLDPWD", old_pwd);
	update_or_create_var(shell, "PWD", new_pwd);
}

char	*simple_operation(char *value, char *re)
{
	if (value)
		free(value);
	return (ft_strdup(re));
}

char	*simple_operation2(t_env	*temp)
{
	if (temp->value)
	{
		printf("%s\n", temp->value);
		return (ft_strdup(temp->value));
	}
	return (NULL);
}
