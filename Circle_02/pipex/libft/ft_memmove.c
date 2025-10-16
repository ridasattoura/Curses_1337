/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 11:17:10 by risattou          #+#    #+#             */
/*   Updated: 2024/10/31 12:39:54 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;

	i = 0;
	if (src == dst)
		return (dst);
	if (&((unsigned char *)src)[i] < &((unsigned char *)dst)[i]
		&& &((unsigned char *)src)[n] > &((unsigned char *)dst)[i])
	{
		while (0 < n)
		{
			n--;
			((unsigned char *)dst)[n] = ((unsigned char *)src)[n];
		}
	}
	else
		return (ft_memcpy(dst, src, n));
	return ((void *)dst);
}
