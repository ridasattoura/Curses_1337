/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 03:59:21 by risattou          #+#    #+#             */
/*   Updated: 2024/07/10 05:09:01 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	*ptr;
	int	i;

	if (max - min <= 0)
	{
		*range = NULL;
		return (0);
	}
	ptr = (int *)malloc((max - min) * sizeof(int));
	if (ptr == NULL)
		return (-1);
	i = 0;
	while (min + i < max)
	{
		ptr[i] = min + i;
		i++;
	}
	*range = ptr;
	return (max - min);
}
