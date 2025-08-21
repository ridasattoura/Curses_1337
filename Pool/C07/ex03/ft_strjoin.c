/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:59:18 by risattou          #+#    #+#             */
/*   Updated: 2024/07/11 02:03:27 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

int	ft_len(int size, char **strs, char *sep)
{
	int	len;
	int	i;

	i = 0;
	len = 0;
	while (i < size)
	{
		len = len + ft_strlen(strs[i]) + ft_strlen(sep);
		i++;
	}
	len -= ft_strlen(sep);
	return (len);
}

char	*ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	len = ft_strlen(dest);
	i = 0;
	while (src[i] != '\0')
	{
		dest[len] = src[i];
		len++;
		i++;
	}
	dest[len] = '\0';
	return (dest);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*new_str;
	int		len;
	int		i;

	len = 0;
	if (size > 0)
		len = ft_len(size, strs, sep);
	new_str = malloc(len + 1);
	if (new_str == NULL)
		return (NULL);
	i = 0;
	new_str[i] = '\0';
	while (i < size)
	{
		ft_strcat(new_str, strs[i]);
		if (i < (size - 1))
			ft_strcat(new_str, sep);
		i++;
	}
	return (new_str);
}
