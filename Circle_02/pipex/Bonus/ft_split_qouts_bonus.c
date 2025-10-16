/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_qouts_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:59:42 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 22:12:44 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*ft_strdup_qouts(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	while (str[i] != c && str[i])
		i++;
	new = (char *)malloc(i + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i] != c && str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}

void	*ft_free_qouts(char **new, int index)
{
	while (index >= 0)
		free(new[index--]);
	free(new);
	return (NULL);
}

int	ft_count(char const *str, char c)
{
	t_qouts	qouts;

	qouts.index = 0;
	qouts.count = 0;
	while (str[qouts.index] != '\0')
	{
		if (skip_delimiters(str, &qouts, c) == 0)
			return (0);
		count_words(str, &qouts, c);
	}
	return (qouts.count);
}

int	ft_home(char **new, char *str)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (str[i])
	{
		if (!process_quotes(new, str, &i, &index))
			return (0);
		if (!process_non_quotes(new, str, &i, &index))
			return (0);
	}
	new[index] = NULL;
	return (1);
}

char	**ft_split_qouts(char const *str, char c)
{
	int		cont;
	char	**new;

	if (!str)
		return (NULL);
	cont = ft_count(str, c) + 1;
	if (cont == 1)
		return (NULL);
	new = (char **)malloc(sizeof(char *) * cont);
	if (new == NULL)
		return (NULL);
	if (!ft_home(new, (char *)str))
		return (NULL);
	return (new);
}
