/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_side_enemy_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/25 16:09:33 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 11:32:49 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_side_enemy_left_on(t_map *all)
{
	if (all->time < 2)
	{
		all->enemy[1]->enabled = true;
		all->enemy[0]->enabled = false;
		all->time++;
	}
	else if (all->time < 8)
	{
		all->enemy[2]->enabled = true;
		all->enemy[1]->enabled = false;
		all->time++;
	}
	else if (all->time < 14)
	{
		all->enemy[3]->enabled = true;
		all->enemy[2]->enabled = false;
		all->time++;
	}
	else
	{
		all->enemy[0]->enabled = true;
		all->enemy[3]->enabled = false;
		all->time = 0;
	}
}

void	ft_side_enemy_right_on(t_map *all)
{
	if (all->time < 2)
	{
		all->enemy[5]->enabled = true;
		all->enemy[4]->enabled = false;
		all->time++;
	}
	else if (all->time < 8)
	{
		all->enemy[6]->enabled = true;
		all->enemy[5]->enabled = false;
		all->time++;
	}
	else if (all->time < 14)
	{
		all->enemy[7]->enabled = true;
		all->enemy[6]->enabled = false;
		all->time++;
	}
	else
	{
		all->enemy[4]->enabled = true;
		all->enemy[7]->enabled = false;
		all->time = 0;
	}
}
