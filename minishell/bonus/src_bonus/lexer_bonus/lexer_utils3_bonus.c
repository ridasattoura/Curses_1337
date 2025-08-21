/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils3_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 21:04:43 by amn               #+#    #+#             */
/*   Updated: 2025/07/09 16:54:15 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

char	*strip_quotes(const char *s)
{
	int	len;

	len = ft_strlen(s);
	return (ft_substr(s, 1, len - 2));
}

char	*ft_strjoin_free(char *s1, char *s2, int strip)
{
	char	*joined;

	if (strip)
		joined = ft_strjoin(s1, strip_quotes(s2));
	else
		joined = ft_strjoin(s1, s2);
	free(s1);
	free(s2);
	return (joined);
}

t_token	*new_token(t_token_type type, char *value)
{
	t_token	*new;

	if (!value)
		return (NULL);
	new = malloc(sizeof(t_token));
	if (!new)
		return (NULL);
	new->next = NULL;
	new->prev = NULL;
	new->type = type;
	new->value = value;
	return (new);
}
