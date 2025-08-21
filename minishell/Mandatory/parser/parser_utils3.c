/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils3.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/15 01:47:07 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 07:26:03 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// bool	is_cmd_or_redir(t_token *tok)
// {
// 	return (tok && (tok->type == COMMAND || tok->type == REDIRECT_IN
// 			|| tok->type == REDIRECT_OUT || tok->type == APPEND
// 			|| tok->type == HEREDOC));
// }

void	ft_print_error(int error)
{
	if (error == 0)
		printf(ERR0);
	else if (error == 1)
		printf(SYNTAX ERR1);
	else if (error == 2)
		printf(SYNTAX ERR2);
	else if (error == 3)
		printf(SYNTAX ERR3);
	else if (error == 4)
		printf(SYNTAX ERR4);
	else if (error == 5)
		printf(SYNTAX ERR5);
	else if (error == 6)
		printf(SYNTAX ERR6);
	else if (error == 7)
		printf(SYNTAX ERR7);
	else if (error == 8)
		printf(SYNTAX ERR8);
	else if (error == 9)
		printf(SYNTAX ERR9);
	else if (error == 10)
		printf(SYNTAX ERR10);
	else if (error == 11)
		printf(ERR11);
}
