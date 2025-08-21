/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 07:44:22 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:55:24 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	is_builtins(char **av)
{
	if (!av)
		return (-1);
	if (!ft_strncmp(av[0], "cd", ft_strlen("cd"))
		&& ft_strlen(av[0]) == ft_strlen("cd"))
		return (0);
	if (!ft_strncmp(av[0], "echo", ft_strlen("echo"))
		&& ft_strlen(av[0]) == ft_strlen("echo"))
		return (1);
	if (!ft_strncmp(av[0], "env", ft_strlen("env"))
		&& ft_strlen(av[0]) == ft_strlen("env"))
		return (2);
	if (!ft_strncmp(av[0], "exit", ft_strlen("exit"))
		&& ft_strlen(av[0]) == ft_strlen("exit"))
		return (3);
	if (!ft_strncmp(av[0], "export", ft_strlen("export"))
		&& ft_strlen(av[0]) == ft_strlen("export"))
		return (4);
	if (!ft_strncmp(av[0], "pwd", ft_strlen("pwd"))
		&& ft_strlen(av[0]) == ft_strlen("pwd"))
		return (5);
	if (!ft_strncmp(av[0], "unset", ft_strlen("unset"))
		&& ft_strlen(av[0]) == ft_strlen("unset"))
		return (6);
	return (-1);
}

void	close_2(int in, int out)
{
	close(in);
	close(out);
}

char	*remove_first_value_quotes(char *str)
{
	t_quote	flag;
	char	*new;
	int		i;

	i = 0;
	flag = NO_QUOTE;
	new = ft_strdup("");
	while (str[i])
	{
		if (set_flag_remove(str, &i, &flag))
			i++;
		else
			new = no_expand(str[i++], new);
	}
	return (new);
}

void	remove_quotes_from_tokens(t_token *list)
{
	char	*tmp;

	while (list)
	{
		tmp = list->value;
		list->value = remove_first_value_quotes(list->value);
		free(tmp);
		list = list->next;
	}
}

void	expand_processing(t_shell *shell, int *fdin, int *fdout)
{
	*fdin = -1;
	*fdout = -1;
	shell->ast_root->full_cmd = full_expand(shell->ast_root->full_cmd,
			shell->envp_list, shell->exit_status);
	remove_quotes_from_tokens(shell->ast_root->full_cmd->args);
	remove_quotes_from_tokens(shell->ast_root->full_cmd->red_in);
	remove_quotes_from_tokens(shell->ast_root->full_cmd->red_out);
	ambiguous_redirection(shell->ast_root);
	shell->ast_root->full_cmd->cmd = transform_args(shell
			->ast_root->full_cmd->args);
}
