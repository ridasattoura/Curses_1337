/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:50:14 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 07:28:46 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	wait_function(int *status1, int *status2, int id1, int id2)
{
	waitpid(id1, status1, 0);
	waitpid(id2, status2, 0);
	signal(2, SIG_IGN);
	signal(3, SIG_IGN);
}

void	signal_handling(int id1, int id2, t_shell *shell)
{
	int	status1;
	int	status2;
	int	sig;

	sig = -1;
	wait_function(&status1, &status2, id1, id2);
	if (WIFSIGNALED(status1))
		sig = WTERMSIG(status1);
	else if (WIFSIGNALED(status2))
		sig = WTERMSIG(status2);
	if (sig == SIGINT || sig == SIGQUIT)
	{
		if (sig == SIGINT)
			write(STDOUT_FILENO, "\n", 1);
		else if (sig == SIGQUIT)
			write(STDOUT_FILENO, "Quit: 3\n", 8);
		shell->exit_status = 128 + sig;
	}
	else
		shell->exit_status = WEXITSTATUS(status2);
	signal(2, ff);
}
