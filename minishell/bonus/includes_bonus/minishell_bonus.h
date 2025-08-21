/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:04:57 by amn               #+#    #+#             */
/*   Updated: 2025/07/20 08:54:55 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_BONUS_H
# define MINISHELL_BONUS_H

# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "builtins_bonus.h"
# include "execution_bonus.h"
# include "expand_bonus.h"
# include "lexer_bonus.h"
# include "parsing_bonus.h"
# include <dirent.h>
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

void	ff(int i);
void	init_main(t_shell *shell, char **envp);
void	cleanup(t_shell *shell, t_token *list);
void	execution(t_shell *shell);
#endif
