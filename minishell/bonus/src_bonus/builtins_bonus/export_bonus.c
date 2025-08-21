/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/17 12:37:08 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:01 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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

static void	process_export_args(t_shell *shell, char **args)
{
	t_env	*temp;
	int		i;

	i = 1;
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

void	ft_export(t_shell *shell)
{
	char	**args;

	args = shell->ast_root->full_cmd->cmd;
	if (check_valid_export(args))
	{
		ft_putstr_fd(" export: `", 2);
		ft_putstr_fd(args[1], 2);
		ft_putstr_fd("': not a valid identifier\n", 2);
		shell->exit_status = 1;
		return ;
	}
	if (!args[1])
	{
		print_exp_list(shell->envp_list);
		shell->exit_status = 0;
		return ;
	}
	process_export_args(shell, args);
}
