/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/22 00:25:36 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 06:29:50 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "minishell.h"

void	code_handle(int *i, char **expanded, t_token *cmd, int exit_status)
{
	char	*tmp;
	char	*var;

	var = NULL;
	if (cmd->value[(*i) + 1] == '?')
	{
		var = ft_itoa(exit_status);
		(*i) += 2;
	}
	else if (cmd->value[(*i) + 1] == '0')
	{
		var = ft_strdup("./minishell");
		(*i) += 2;
	}
	if (var)
	{
		tmp = *expanded;
		*expanded = ft_strjoin(*expanded, var);
		free_two(tmp, var);
	}
}

void	expand_token(t_token *cmd, t_env *envp_list, t_token **new, t_norm *mix)
{
	t_quote	flag;
	int		i;
	int		start;
	char	*expanded;
	bool	was_quoted;

	if (!cmd || !cmd->value)
		return ;
	init_expand(&i, &flag, &start, &expanded);
	was_quoted = (ft_strchr(cmd->value, '\'') || ft_strchr(cmd->value, '"'));
	
	while (cmd->value[i])
	{
		if ((cmd->value[i] == '\'' || cmd->value[i] == '"'))
		{
			if (set_flag(cmd->value, &i, &flag))
			{
				i++;
				continue;
			}
		}
		if (cmd->value[i] == '$' && flag != IN_S_QUOTE)
		{
			start = i;
			code_handle(&i, &expanded, cmd, mix->exit_status);
			if (i == start) 
				core_handling(&i, &expanded, cmd, envp_list);
		}
		else
			expanded = no_expand(cmd->value[i++], expanded);
	}
	if (!was_quoted && expanded && ft_strchr(expanded, ' '))
		additional_handling(cmd, new, &expanded);
	else
		add_token(new, new_token(cmd->type, expanded));
	if (ft_strlen(expanded) == 0)
		*mix->is_ambigious = 1;
}

void	init_exp(t_norm	*mix, int exit_status, int *ambigious)
{
	mix->is_export = 0;
	mix->exit_status = exit_status;
	mix->is_ambigious = ambigious;
}
t_token	*ft_expand(t_token *list, t_env *envp_list, int exit_status, int *ambigious)
{
	t_token	*temp;
	t_token	*new;
	t_norm	mix;

	temp = list;
	new = NULL;
	init_exp(&mix, exit_status, ambigious);
	if (list && !ft_strncmp(list->value, "export", ft_strlen(list->value)))
		mix.is_export = 1;
	while (list)
	{
		if (list->type == HEREDOC)
		{
			list->type = expand_check(list->value);
			add_token(&new, new_token(list->type, ft_strdup(list->value)));
			exchange_quotes(new);
			list = list->next;
			continue ;
		}
		expand_token(list, envp_list, &new, &mix);
		list = list->next;
	}
	free_list(temp);
	return (new);
}

t_full_cmd	*full_expand(t_full_cmd *cmd, t_env *envp_list, int exit_status)
{
	t_full_cmd	*expanded;

	expanded = cmd;
	expanded->cmd = NULL;
	expanded->red_in = ft_expand(cmd->red_in, envp_list, exit_status, &cmd->ambigious);
	expanded->red_out = ft_expand(cmd->red_out, envp_list, exit_status, &cmd->ambigious);
	expanded->args = ft_expand(cmd->args, envp_list, exit_status, &cmd->ambigious);
	// print_token_list(expanded->args);
	if ((cmd->red_in && !expanded->red_in) || (cmd->red_out
			&& !expanded->red_out) || (cmd->args && !expanded->args))
		return (ft_print_error(0), NULL);
	return (expanded);
}
// #include "minishell.h"

// void	code_handle(int *i, char **expanded, t_token *cmd, int exit_status)
// {
// 	char	*tmp;
// 	char	*var;
// 	int		flag;

// 	var = NULL;
// 	flag = 0;
// 	if (cmd->value[(*i) + 1] == '?')
// 	{
// 		flag = 1;
// 		var = ft_itoa(exit_status);
// 		(*i) += 2;
// 	}
// 	else if (cmd->value[(*i) + 1] == '0')
// 	{
// 		flag = 1;
// 		var = ft_strdup("./minishell");
// 		(*i) += 2;
// 	}
// 	if (flag)
// 	{
// 		tmp = *expanded;
// 		*expanded = ft_strjoin(*expanded, var);
// 		free_two(tmp, var);
// 	}
// }

// void	expand_token(t_token *cmd, t_env *envp_list, t_token **new, t_norm *mix)
// {
// 	t_quote	flag;
// 	int		i;
// 	int		start;
// 	char	*expanded;

// 	init_expand(&i, &flag, &start, &expanded);
// 	while (cmd->value[i])
// 	{
// 		if ((cmd->value[i] == '\'' || cmd->value[i] == '"'))
// 			set_flag(cmd->value, &i, &flag);
// 		if (cmd->value[i] == '$' && flag != IN_S_QUOTE)
// 		{
// 			start = i;
// 			code_handle(&i, &expanded, cmd, mix->exit_status);
// 			if (i == start) 
// 				core_handling(&i, &expanded, cmd, envp_list);
// 		}
// 		else
// 			expanded = no_expand(cmd->value[i++], expanded);
// 	}
// 	if (mix->is_export && flag != IN_S_QUOTE)
// 		additional_handling(cmd, new, &expanded);
// 	else
// 		add_token(new, new_token(cmd->type, expanded));
// 	if (ft_strlen(expanded) == 0)
// 		*mix->is_ambigious = 1;
// }

// void	init_exp(t_norm	*mix, int exit_status, int *ambigious)
// {
// 	mix->is_export = 0;
// 	mix->exit_status = exit_status;
// 	mix->is_ambigious = ambigious;
// }
// t_token	*ft_expand(t_token *list, t_env *envp_list, int exit_status, int *ambigious)
// {
// 	t_token	*temp;
// 	t_token	*new;
// 	t_norm	mix;

// 	temp = list;
// 	new = NULL;
// 	init_exp(&mix, exit_status, ambigious);
// 	if (list && ft_strncmp(list->value, "export", ft_strlen(list->value)))
// 		mix.is_export = 1;
// 	while (list)
// 	{
// 		if (list->type == HEREDOC)
// 		{
// 			list->type = expand_check(list->value);
// 			add_token(&new, new_token(list->type, ft_strdup(list->value)));
// 			exchange_quotes(new);
// 			list = list->next;
// 			continue ;
// 		}
// 		expand_token(list, envp_list, &new, &mix);
// 		list = list->next;
// 	}
// 	free_list(temp);
// 	return (new);
// }

// t_full_cmd	*full_expand(t_full_cmd *cmd, t_env *envp_list, int exit_status)
// {
// 	t_full_cmd	*expanded;

// 	expanded = cmd;
// 	expanded->cmd = NULL;
// 	expanded->red_in = ft_expand(cmd->red_in, envp_list, exit_status, &cmd->ambigious);
// 	expanded->red_out = ft_expand(cmd->red_out, envp_list, exit_status, &cmd->ambigious);
// 	expanded->args = ft_expand(cmd->args, envp_list, exit_status, &cmd->ambigious);
// 	// print_token_list(expanded->args);
// 	if ((cmd->red_in && !expanded->red_in) || (cmd->red_out
// 			&& !expanded->red_out) || (cmd->args && !expanded->args))
// 		return (ft_print_error(0), NULL);
// 	return (expanded);
// }
