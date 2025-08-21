/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:13:01 by risattou          #+#    #+#             */
/*   Updated: 2024/11/07 00:13:02 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	len1;
	char	*new;

	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1);
	len1 = len + ft_strlen(s2);
	new = (char *)malloc(len1 + 1);
	if (new == NULL)
		return (NULL);
	ft_strlcpy(new, s1, len + 1);
	ft_strlcat(new, s2, len1 + 1);
	return (new);
}
