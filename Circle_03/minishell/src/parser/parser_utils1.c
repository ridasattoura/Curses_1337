/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:31:49 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 03:04:53 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

bool	is_redirection(t_token_type type)
{
	return (type == REDIRECT_IN || type == REDIRECT_OUT || type == APPEND
		|| type == HEREDOC);
}

bool	redirection_handle(t_token **list)
{
	t_token	*ptr;
	t_token	*tmp;

	ptr = *list;
	while (ptr)
	{
		if (is_redirection(ptr->type))
		{
			if (!ptr->next || ptr->next->type != COMMAND)
				return (ft_print_error(9), false);
			else
			{
				ptr->next->type = ptr->type;
				tmp = ptr;
				ptr = ptr->next;
				remove_node(list, tmp);
			}
		}
		ptr = ptr->next;
	}
	return (true);
}

char	**transform_args(t_token *args)
{
	t_token	*ptr;
	int		len;
	int		i;
	char	**matrix;

	if (!args)
		return (NULL);
	i = 0;
	len = 0;
	ptr = args;
	while (ptr)
	{
		len++;
		ptr = ptr->next;
	}
	matrix = malloc(sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	ptr = args;
	while (i < len)
	{
		matrix[i++] = ft_strdup(ptr->value);
		ptr = ptr->next;
	}
	matrix[i] = NULL;
	return (matrix);
}

t_full_cmd	*init_cmd(void)
{
	t_full_cmd	*cmd;

	cmd = malloc(sizeof(t_full_cmd));
	if (!cmd)
		return (NULL);
	cmd->args = NULL;
	cmd->red_in = NULL;
	cmd->red_out = NULL;
	cmd->cmd = NULL;
	cmd->fd = -1;
	cmd->ambigious = 0;
	return (cmd);
}

t_full_cmd	*commands_handle(t_token **list, t_full_cmd *cmd)
{
	t_token	*temp;

	temp = *list;
	cmd = init_cmd();
	while (temp)
	{
		if (temp->type == REDIRECT_IN || temp->type == HEREDOC)
			add_token(&cmd->red_in, new_token(temp->type,
					ft_strdup(temp->value)));
		else if (temp->type == REDIRECT_OUT || temp->type == APPEND)
			add_token(&cmd->red_out, new_token(temp->type,
					ft_strdup(temp->value)));
		else
			add_token(&cmd->args, new_token(temp->type,
					ft_strdup(temp->value)));
		temp = temp->next;
	}
	return (cmd);
}
