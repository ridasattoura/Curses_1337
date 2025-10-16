/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amine <amine@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/14 12:11:14 by mohchaib          #+#    #+#             */
/*   Updated: 2025/05/18 12:48:24 by amine            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	cleanup(t_shell *shell, t_token *list)
{
	if (list)
		free_list(list);
	if (shell && shell->ast_root)
		free_tree(shell->ast_root);
}

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
	if (!syntax_error(list, shell))
	{
		shell->exit_status = 258;
		return (cleanup(shell, list));
	}
	shell->ast_root = create_tree(list);
	if (!shell->ast_root)
		return (cleanup(shell, list));
	her_her(shell->ast_root,&shell->exit_status);
	if (shell->exit_status != -2)
		exec(shell, 0);
	else
		shell->exit_status = 1;
	close_heredoc_fds(shell->ast_root);
	free_tree(shell->ast_root);
}

void	ff(int i)
{
	(void)i;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

int	main(int argc, char **argv, char **envp)
{
	t_shell	shell;
	char	*line;

	if (argc != 1)
		return (printf("Usage : %s\n", argv[0]), 1);
	signal(2, ff);
	signal(SIGQUIT, SIG_IGN);
	shell.exit_status = 0;
	shell.envp_list = envp_list(envp);
	ft_update_envp(&shell, 0);
	// if (!shell.envp_list)
	// 	return (1);
	while (1)
	{
		line = readline(GREEN "minishell> " RESET);
		if (!line)
		{
			free_envp(shell.envp_list,shell.env);
			printf(RED "exit\n" RESET);
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
