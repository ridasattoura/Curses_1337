/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:59:24 by risattou          #+#    #+#             */
/*   Updated: 2024/07/11 14:05:56 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	j;
	int	*ptr;

	if ((max - min) <= 0)
		return (NULL);
	ptr = (int *)malloc((max - min) * sizeof(int));
	if (ptr == NULL)
		return (NULL);
	j = 0;
	while (min < max)
	{
		ptr[j] = min;
		min++;
		j++;
	}
	return (ptr);
}
