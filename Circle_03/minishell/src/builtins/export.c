/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:37:08 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 03:56:08 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*ft_strdup_var(const char *s, int j)
{
	size_t	i;
	size_t	size;
	char	*new;

	i = 0;
	size = j;
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	while (i < (size_t)j)
	{
		new[i] = s[i];
		i++;
	}
	new[i] = 0;
	return (new);
}

int	ft_strlen_(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '=' || (str[i] == '+' && str[i + 1] == '='))
			break ;
		i++;
	}
	return (i);
}

void	print_exp_list(t_env *envp_list)
{
	t_env	*head;

	head = envp_list;
	while (head != NULL)
	{
		printf("declare -x %s", head->variable);
		if (head->is_export == 1)
		{
			printf("=");
			if (head->value)
				printf("\"%s\"", head->value);
		}
		printf("\n");
		head = head->next;
	}
}

static void	ft_lstadd_back_env(t_env **lst, t_env *new)
{
	t_env	*ptr;

	if (!new || !lst)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	ptr = *lst;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

void	ft_export(t_shell *shell)
{
	char	**args;
	t_env	*temp;
	int		i;

	i = 1;
	args = shell->ast_root->full_cmd->cmd;
	if (check_valid_export(args))
	{
		ft_putstr_fd(" export: `", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		shell->exit_status = 1;
		return ;
	}
	if (!args[i])
	{
		print_exp_list(shell->envp_list);
		shell->exit_status = 0;
		return ;
	}
	while (args[i])
	{
		if (ft_check_var(shell->envp_list, args[i]) == 0)
		{
			i++;
			continue ;
		}
		temp = ft_creat_var(args[i]);
		if (temp)
			ft_lstadd_back_env(&shell->envp_list, temp);
		i++;
	}
	shell->exit_status = 0;
}
