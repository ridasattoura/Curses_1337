/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:13:53 by risattou          #+#    #+#             */
/*   Updated: 2024/11/07 00:13:55 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_ft(void)
{
	char	*new;

	new = malloc(1);
	if (new == NULL)
		return (NULL);
	new[0] = '\0';
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
		return (ft_ft());
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
