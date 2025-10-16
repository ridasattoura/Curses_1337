/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipe_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:50:14 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/08 02:05:03 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	signal_handling(int id1, int id2, t_shell *shell)
{
	int	status1;
	int	status2;
	int	sig;

	waitpid(id1, &status1, 0);
	waitpid(id2, &status2, 0);
	signal(2, SIG_IGN);
	signal(3, SIG_IGN);
	sig = -1;
	if (WIFSIGNALED(status1))
		sig = WTERMSIG(status1);
	else if (WIFSIGNALED(status2))
		sig = WTERMSIG(status2);
	if (sig == SIGINT || sig == SIGQUIT)
	{
		if (sig == SIGINT)
		{
			write(STDOUT_FILENO, "\n", 1);
			shell->exit_status = 128 + sig;
		}
		else if (sig == SIGQUIT)
		{
			write(STDOUT_FILENO, "Quit: 3\n", 8);
			shell->exit_status = 128 + sig;
		}
	}
	else
		shell->exit_status = WEXITSTATUS(status2);
	signal(2, ff);
}
