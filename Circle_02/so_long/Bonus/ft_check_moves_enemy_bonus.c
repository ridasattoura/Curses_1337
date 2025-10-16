/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_moves_enemy_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/18 17:20:04 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 11:32:32 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_enemy_up(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		enemy_x = all->enemy[0]->instances[0].x;
		enemy_y = all->enemy[0]->instances[0].y - 40;
		if ((((block_x - enemy_x) < 40 && (block_x - enemy_x) > -40))
			&& block_y == enemy_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_enemy_down(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		enemy_x = all->enemy[0]->instances[0].x;
		enemy_y = all->enemy[0]->instances[0].y + 40;
		if ((((block_x - enemy_x) < 40 && (block_x - enemy_x) > -40))
			&& block_y == enemy_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_enemy_left(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		enemy_x = all->enemy[0]->instances[0].x - 40;
		enemy_y = all->enemy[0]->instances[0].y;
		if ((block_x == enemy_x && ((block_y - enemy_y) < 40 && (block_y
						- enemy_y) > -40)))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_enemy_right(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	enemy_x;
	int	enemy_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		enemy_x = all->enemy[0]->instances[0].x + 40;
		enemy_y = all->enemy[0]->instances[0].y;
		if ((block_x == enemy_x && ((block_y - enemy_y) < 40 && (block_y
						- enemy_y) > -40)))
			return (1);
		i++;
	}
	return (0);
}

void	ft_steps_enemy(t_map *all, int x, int y)
{
	int	i;

	if (x != 0)
		ft_turn_off(all, x, 0);
	if (all->enemy[0]->enabled == true)
		ft_side_enemy_left_on(all);
	if (all->enemy[4]->enabled == true)
		ft_side_enemy_right_on(all);
	i = 0;
	while (i < 8)
	{
		all->enemy[i]->instances[0].x += x;
		all->enemy[i]->instances[0].y += y;
		i++;
	}
}
