/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: codespace <codespace@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/10 02:04:57 by amn               #+#    #+#             */
/*   Updated: 2025/07/09 16:08:56 by codespace        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# define RED "\033[31m"
# define GREEN "\033[32m"
# define YELLOW "\033[33m"
# define BLUE "\033[34m"
# define CYAN "\033[36m"
# define RESET "\033[0m"

# include "../../get_next_line/get_next_line.h"
# include "../../libft/libft.h"
# include "builtins.h"
# include "execution.h"
# include "expand.h"
# include "lexer.h"
# include "parsing.h"
# include <dirent.h>
# include <stdio.h>
# include <errno.h>
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
