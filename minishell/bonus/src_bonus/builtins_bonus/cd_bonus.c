/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd_bonus.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 18:23:30 by risattou          #+#    #+#             */
/*   Updated: 2025/07/20 17:02:14 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*tylda_handle(t_env	*temp, t_shell *shell)
{
	temp = shell->envp_list;
	while (temp)
	{
		if (ft_strncmp("HOME", temp->variable, 5) == 0)
			return (ft_strdup(temp->value));
		temp = temp->next;
	}
	ft_putstr_fd("cd: HOME not set\n", 2);
	shell->exit_status = 1;
	return (NULL);
}

char	*get_target_directory(t_shell *shell)
{
	t_env	*temp;
	char	*arg;

	temp = NULL;
	arg = shell->ast_root->full_cmd->cmd[1];
	if (!arg || (arg[0] == '~' && arg[1] == '\0'))
		return (tylda_handle(temp, shell));
	else if (ft_strncmp(arg, "-", 2) == 0)
	{
		temp = shell->envp_list;
		while (temp)
		{
			if (ft_strncmp("OLDPWD", temp->variable, 6) == 0
				&& temp->variable[6] == '\0')
				simple_operation2(temp);
			temp = temp->next;
		}
		ft_putstr_fd("cd: OLDPWD not set\n", 2);
		shell->exit_status = 1;
		return (NULL);
	}
	return (ft_strdup(arg));
}

void	update_or_create_var(t_shell *shell, char *var_name, char *value)
{
	t_env	*temp;
	t_env	*new_var;

	temp = shell->envp_list;
	while (temp)
	{
		if (ft_strncmp(var_name, temp->variable, ft_strlen(var_name)) == 0
			&& temp->variable[ft_strlen(var_name)] == '\0')
		{
			temp->value = simple_operation(temp->value, value);
			return ;
		}
		temp = temp->next;
	}
	if (!init_cd(&new_var, var_name, value))
		return ;
	if (!shell->envp_list)
		shell->envp_list = new_var;
	else
	{
		temp = shell->envp_list;
		while (temp->next)
			temp = temp->next;
		temp->next = new_var;
	}
}

bool	cd_core(t_shell *shell, char *old_pwd, char *new_pwd, char	*target_dir)
{
	if (!getcwd(old_pwd, 1024))
	{
		perror("cd: getcwd (old)");
		free(target_dir);
		shell->exit_status = 1;
		return (false);
	}
	if (chdir(target_dir) != 0)
	{
		perror("cd");
		free(target_dir);
		shell->exit_status = 1;
		return (false);
	}
	if (!getcwd(new_pwd, 1024))
	{
		perror("cd: getcwd (new)");
		free(target_dir);
		shell->exit_status = 1;
		return (false);
	}
	return (true);
}

void	ft_cd(t_shell *shell)
{
	char	old_pwd[1024];
	char	new_pwd[1024];
	char	*target_dir;

	target_dir = get_target_directory(shell);
	if (!target_dir)
		return ;
	if (!cd_core(shell, old_pwd, new_pwd, target_dir))
		return ;
	update_env_variables(shell, old_pwd, new_pwd);
	free(target_dir);
	shell->exit_status = 0;
}
