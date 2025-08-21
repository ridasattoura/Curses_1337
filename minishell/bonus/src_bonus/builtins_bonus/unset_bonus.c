/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:19:27 by risattou          #+#    #+#             */
/*   Updated: 2025/07/20 16:25:41 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

static int	is_valid_identifier(char *str)
{
	int	i;

	if (!str || !*str)
		return (0);
	if (ft_isdigit(str[0]) || str[0] == '=' || str[0] == '+' || str[0] == '-')
		return (0);
	i = 0;
	while (str[i])
	{
		if (!ft_isalnum(str[i]) && str[i] != '_')
			return (0);
		i++;
	}
	return (1);
}

static void	remove_env_var(t_shell *shell, char *var_name)
{
	t_env	*temp;
	t_env	*prev;
	t_env	*to_free;

	prev = NULL;
	temp = shell->envp_list;
	while (temp)
	{
		if (ft_strncmp(temp->variable, var_name, ft_strlen(var_name) + 1) == 0)
		{
			to_free = temp;
			if (prev)
				prev->next = temp->next;
			else
				shell->envp_list = temp->next;
			free(to_free->variable);
			free(to_free->value);
			free(to_free);
			return ;
		}
		prev = temp;
		temp = temp->next;
	}
}

void	unset_error(char c, int *error_flag)
{
	ft_putstr_fd("unset: `", 2);
	ft_putstr_fd(&c, 2);
	ft_putstr_fd("': not a valid identifier\n", 2);
	(*error_flag) = 1;
}

void	ft_unset(t_shell *shell)
{
	char	**args;
	int		i;
	int		error_flag;

	args = shell->ast_root->full_cmd->cmd;
	error_flag = 0;
	i = 1;
	while (args[i])
	{
		if (ft_strncmp(args[i], "_", 2) == 0)
		{
			i++;
			continue ;
		}
		if (!is_valid_identifier(args[i]))
			unset_error(*args[i], &error_flag);
		else
		{
			remove_env_var(shell, args[i]);
		}
		i++;
	}
	shell->exit_status = error_flag;
}
