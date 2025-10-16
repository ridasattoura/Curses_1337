/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 23:16:24 by risattou          #+#    #+#             */
/*   Updated: 2024/11/08 00:25:34 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*new;
	size_t	i;
	size_t	t;

	t = count * size;
	if ((t != 0) && (count != t / size))
		return (NULL);
	i = 0;
	new = (void *)malloc(t);
	if (new == NULL)
		return (NULL);
	while (i < t)
	{
		((char *)new)[i] = 0;
		i++;
	}
	return (new);
}
