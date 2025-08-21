/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/16 21:56:34 by risattou          #+#    #+#             */
/*   Updated: 2024/07/16 21:57:45 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strchar(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
	{
		if (charset[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int	ft_count(char *str, char *charset)
{
	int	cont;
	int	i;

	cont = 0;
	i = 0;
	while (str[i])
	{
		while (ft_strchar(str[i], charset) && str[i])
			i++;
		if (!ft_strchar(str[i], charset) && str[i])
			cont++;
		while (!ft_strchar(str[i], charset) && str[i])
			i++;
	}
	return (cont);
}

char	*ft_strdup(char *src, char *charset)
{
	char	*new_src;
	int		i;
	int		len;

	len = 0;
	while (!ft_strchar(src[len], charset) && src[len])
		len++;
	new_src = (char *)malloc((len + 1) * sizeof(char));
	if (new_src == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

char	**ft_split(char *str, char *charset)
{
	int		cont;
	char	**new;
	int		i;
	int		index;

	cont = ft_count(str, charset) + 1;
	new = (char **)malloc(sizeof(char *) * cont);
	if (new == NULL)
		return (NULL);
	i = 0;
	index = 0;
	while (str[i])
	{
		while (ft_strchar(str[i], charset) && str[i])
			i++;
		if (!ft_strchar(str[i], charset) && str[i])
		{
			new[index] = ft_strdup((str + i), charset);
			index++;
		}
		while (!ft_strchar(str[i], charset) && str[i])
			i++;
	}
	new[index] = NULL;
	return (new);
}
