/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/20 15:53:30 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:55:22 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	error_handle(t_shell *shell, int flag)
{
	if (flag)
		perror("failed in");
	else
		perror("failed out");
	if (shell)
		shell->exit_status = 1;
}

void	ambiguous_handle_(t_shell *shell)
{
	if (shell->ast_root->full_cmd->ambigious == 1)
	{
		printf(ERR12);
		exit(1);
	}
}

void	remove_ambiguous_tokens(t_token **list)
{
	t_token	*temp;
	t_token	*next;

	temp = *list;
	while (temp)
	{
		next = temp->next;
		if (ft_strlen(temp->value) == 0)
		{
			remove_node(list, temp);
			temp = next;
			continue ;
		}
		temp = next;
	}
}

void	ambiguous_redirection(t_ast *tree)
{
	if (!tree)
		return ;
	if (tree->type == COMMAND && tree->full_cmd)
	{
		if (tree->full_cmd->args)
			remove_ambiguous_tokens(&tree->full_cmd->args);
	}
	ambiguous_redirection(tree->left);
	ambiguous_redirection(tree->right);
}

bool	set_flag_remove(char *str, int *i, t_quote *flag)
{
	if (*flag == NO_QUOTE && str[*i] == 1)
	{
		*flag = IN_S_QUOTE;
		return (true);
	}
	else if (*flag == NO_QUOTE && str[*i] == 2)
	{
		*flag = IN_D_QUOTE;
		return (true);
	}
	else if (str[*i] == 1 && *flag == IN_S_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	else if (str[*i] == 2 && *flag == IN_D_QUOTE)
	{
		*flag = NO_QUOTE;
		return (true);
	}
	return (false);
}
