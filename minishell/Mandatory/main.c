/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:11:14 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:50:24 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	init_shell(t_shell *shell, char *line)
{
	t_token	*list;

	list = NULL;
	list = create_list(line);
	if (!list)
		return (cleanup(shell, list));
	if (!redirection_handle(&list))
	{
		shell->exit_status = 2;
		return (cleanup(shell, list));
	}
	if (!syntax_error(list))
	{
		shell->exit_status = 258;
		return (cleanup(shell, list));
	}
	shell->ast_root = create_tree(list);
	if (!shell->ast_root)
		return (cleanup(shell, list));
	her_her(shell->ast_root, &shell->exit_status);
	execution(shell);
	close_heredoc_fds(shell->ast_root);
	free_tree(shell->ast_root);
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	if (argc != 1)
		return (printf("Usage : %s\n", argv[0]), 1);
	init_main(&shell, envp);
	while (1)
	{
		line = readline("minishell> ");
		if (!line)
		{
			free_envp(shell.envp_list, shell.env);
			printf("exit\n");
			break ;
		}
		if (line && *line)
			add_history(line);
		shell.ast_root = NULL;
		init_shell(&shell, line);
		free(line);
	}
	return (shell.exit_status);
}
