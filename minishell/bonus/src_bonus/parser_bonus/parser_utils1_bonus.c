/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils1_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/11 16:31:49 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:34:47 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

bool	only_whitespaces(char *str)
{
	int		i;
	bool	flag;

	i = 0;
	flag = true;
	while (str[i])
	{
		if (!is_whitespace(str[i]))
			flag = false;
		i++;
	}
	return (flag);
}

int	inc_two_(t_token	*args)
{
	int	len;

	len = 0;
	while (args)
	{
		len++;
		args = args->next;
	}
	return (len);
}

char	**transform_args(t_token *args)
{
	int		len;
	int		i;
	char	**matrix;

	while (args && (!args->value || args->value[0] == '\0'
			|| only_whitespaces(args->value)))
		args = args->next;
	if (!args)
		return (NULL);
	init_trans(&i, &len);
	len = inc_two_(args);
	matrix = malloc(sizeof(char *) * (len + 1));
	if (!matrix)
		return (NULL);
	while (args)
	{
		matrix[i++] = ft_strdup(args->value);
		args = args->next;
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
