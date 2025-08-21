/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 12:41:44 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 15:59:43 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	additional_handling(t_token *cmd, t_token **new, char **expanded)
{
	char	**matrix;
	bool	check;
	int		j;

	j = 0;
	check = true;
	matrix = ft_split(*expanded, ' ');
	while (matrix && matrix[j])
	{
		if (check)
		{
			add_token(new, new_token(cmd->type, ft_strdup(matrix[j++])));
			check = false;
		}
		else
			add_token(new, new_token(AMBIGUOUS, ft_strdup(matrix[j++])));
	}
	free_matrix(matrix);
	free(*expanded);
}

void	core_handling(int *i, char **expanded, t_token *cmd, t_env *envp_list)
{
	char	*tmp;
	char	*var;

	var = expand_variable(cmd->value, i, envp_list);
	if (!var)
		return ;
	tmp = *expanded;
	*expanded = ft_strjoin(*expanded, var);
	free_two(tmp, var);
}

static int	is_delimiter(char c)
{
	return (c == '$' || c == '"' || c == '\''
		|| c == '?' || c == '=' || c == '.'
		|| c == ',' || c == '{' || c == '}'
		|| c == '~' || c == '!' || c == '@'
		|| c == '#' || c == '%' || c == '^'
		|| c == '[' || c == '{' || c == '}'
		|| c == ']' || c == ':' || is_whitespace(c)
	);
}

char	*expand_variable(const char *str, int *i, t_env *envp_list)
{
	int		start;
	int		len;
	char	*name;
	t_env	*var;

	(*i)++;
	start = *i;
	len = 0;
	while (str[start + len] && !is_delimiter(str[start + len]))
		len++;
	if (len == 0)
		return (ft_strdup("$"));
	name = ft_substr(str, start, len);
	if (!name)
		return (NULL);
	var = get_variable_envp(envp_list, name);
	free(name);
	*i = start + len ;
	if (!var || !var->value)
		return (ft_strdup(""));
	return (ft_strdup(var->value));
}

t_token_type	expand_check(char *string)
{
	int	i;

	i = 0;
	while (string[i])
	{
		if (string[i] == '"' || string[i] == '\'')
			return (EXPAND_HERE_DOC);
		i++;
	}
	return (HEREDOC);
}
