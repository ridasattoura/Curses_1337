/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_wall.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 10:26:27 by risattou          #+#    #+#             */
/*   Updated: 2025/03/20 06:10:52 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_check_wall(t_data *source)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < source->height)
	{
		if (i == 0 || i == source->height - 1)
		{
			j = 0;
			while (j < source->width)
			{
				if (source->map[i][j] != '1' && source->map[i][j] != '\0')
					ft_error(NULL);
				j++;
			}
		}
		else
		{
			if (source->map[i][0] != '1' || source->map[i][source->width
				- 1] != '1')
				ft_error(NULL);
		}
		i++;
	}
}
