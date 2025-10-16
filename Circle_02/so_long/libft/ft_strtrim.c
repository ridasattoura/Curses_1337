/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 21:46:12 by risattou          #+#    #+#             */
/*   Updated: 2024/11/04 22:41:39 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strchar(char const *set, char c)
{
	size_t	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

static char	*ft_ft(void)
{
	char	*new;

	new = malloc(1);
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
	return (new);
}

static int	ft_count(char const *set, char const *src, int sign, int i)
{
	while (ft_strchar(set, src[i]) == 1)
		i += sign;
	return (i);
}

char	*ft_strtrim(char const *src, char const *set)
{
	size_t	i;
	size_t	res;
	char	*new;
	size_t	j;

	if (!src || !set)
		return (NULL);
	i = ft_count(set, src, 1, 0);
	if (src[i] == '\0')
		return (ft_ft());
	j = ft_count(set, src, -1, (ft_strlen(src) - 1));
	res = j - i + 2;
	new = malloc(res);
	if (new == NULL)
		return (NULL);
	j = 0;
	while (j < res - 1)
	{
		new[j] = src[i + j];
		j++;
	}
	new[j] = '\0';
	return (new);
}
