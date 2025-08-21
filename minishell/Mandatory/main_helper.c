/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_helper.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 16:15:18 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:26:19 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ff(int i)
{
	(void)i;
	printf("\n");
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
	return ;
}

void	init_main(t_shell *shell, char **envp)
{
	signal(2, ff);
	signal(SIGQUIT, SIG_IGN);
	shell->exit_status = 0;
	shell->envp_list = envp_list(envp);
	ft_update_envp(shell, 0);
}

void	cleanup(t_shell *shell, t_token *list)
{
	if (list)
		free_list(list);
	if (shell && shell->ast_root)
		free_tree(shell->ast_root);
}

void	execution(t_shell *shell)
{
	if (shell->exit_status != -2)
		exec(shell, 0);
	else
		shell->exit_status = 1;
}
