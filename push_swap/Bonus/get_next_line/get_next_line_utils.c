/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:26:35 by risattou          #+#    #+#             */
/*   Updated: 2024/11/16 18:53:57 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	char	*new_src;
	int		i;

	new_src = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new_src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len1;
	size_t	i;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len1 = ft_strlen(s1) + ft_strlen(s2);
	new = (char *)malloc(len1 + 1);
	if (new == NULL)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	len1 = 0;
	while (s2[len1])
	{
		new[i + len1] = s2[len1];
		len1++;
	}
	new[i + len1] = '\0';
	return (new);
}

char	*ft_substr(char const *str, unsigned int start, size_t len)
{
	size_t	i;
	char	*new;

	i = 0;
	if (!str)
		return (NULL);
	if (ft_strlen(str) < start)
		return (ft_strdup(""));
	while (str[i + start] && (i) < len)
		i++;
	new = (char *)malloc((i + 1) * sizeof(char));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (str[i + start] && i < len)
	{
		new[i] = str[i + start];
		i++;
	}
	new[i] = '\0';
	return (new);
}

int	ft_strchr(const char *str, int c)
{
	size_t	i;

	if (!str)
		return (-1);
	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (-1);
}
