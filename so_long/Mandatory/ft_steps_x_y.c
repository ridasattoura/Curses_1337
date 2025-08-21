/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps_x_y.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:50:34 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 21:54:13 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_steps(t_map *all, int x, int y)
{
	int	i;

	i = 0;
	all->movement += 1;
	if (x != 0)
		ft_turn_off(all, x, 1);
	while (i < 8)
	{
		all->hero[i]->instances[0].x += x;
		all->hero[i]->instances[0].y += y;
		i++;
	}
}
