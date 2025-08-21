/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:12:52 by risattou          #+#    #+#             */
/*   Updated: 2024/11/07 00:12:53 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
