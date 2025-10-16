/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:59:42 by risattou          #+#    #+#             */
/*   Updated: 2024/11/04 22:02:09 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count(char const *str, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			cont++;
		while (str[i] != c && str[i])
			i++;
	}
	return (cont);
}

static char	*ft_strdupp(char *str, char c)
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

static void	*ft_free(char **new, int index)
{
	while (index >= 0)
		free(new[index--]);
	free(new);
	return (NULL);
}

static int	ft_home(char **new, char *str, char c)
{
	int	index;
	int	i;

	index = 0;
	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			new[index] = ft_strdupp((char *)(str + i), c);
			if (new[index] == NULL)
			{
				ft_free(new, index);
				return (0);
			}
			index++;
		}
		while (str[i] != c && str[i])
			i++;
	}
	new[index] = NULL;
	return (1);
}

char	**ft_split(char const *str, char c)
{
	int		cont;
	char	**new;

	if (!str)
		return (NULL);
	cont = ft_count(str, c) + 1;
	new = (char **)malloc(sizeof(char *) * cont);
	if (new == NULL)
		return (NULL);
	if (!ft_home(new, (char *)str, c))
		return (NULL);
	return (new);
}
