/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_moves.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:19:38 by risattou          #+#    #+#             */
/*   Updated: 2025/02/24 15:19:48 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_up(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	player_x;
	int	player_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		player_x = (all->hero[0]->instances[0].x);
		player_y = (all->hero[0]->instances[0].y - 40);
		if ((((block_x - player_x) < 40 && (block_x - player_x) > -40))
			&& block_y == player_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_down(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	player_x;
	int	player_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = (all->the_wall->instances[i].x);
		block_y = all->the_wall->instances[i].y;
		player_x = (all->hero[0]->instances[0].x);
		player_y = (all->hero[0]->instances[0].y + 40);
		if ((((block_x - player_x) < 40 && (block_x - player_x) > -40))
			&& block_y == player_y)
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_left(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	player_x;
	int	player_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		player_x = (all->hero[0]->instances[0].x - 40);
		player_y = all->hero[0]->instances[0].y;
		if ((block_x == player_x && ((block_y - player_y) < 40 && (block_y
						- player_y) > -40)))
			return (1);
		i++;
	}
	return (0);
}

int	ft_check_right(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	player_x;
	int	player_y;

	i = 0;
	while (i < all->count_wall)
	{
		block_x = all->the_wall->instances[i].x;
		block_y = all->the_wall->instances[i].y;
		player_x = (all->hero[0]->instances[0].x + 40);
		player_y = all->hero[0]->instances[0].y;
		if ((block_x == player_x && ((block_y - player_y) < 40 && (block_y
						- player_y) > -40)))
			return (1);
		i++;
	}
	return (0);
}

void	ft_check_coins(t_map *all)
{
	int	i;
	int	block_x;
	int	block_y;
	int	player_x;
	int	player_y;

	i = 0;
	while (i < all->count_coins)
	{
		block_x = all->coins->instances[i].x;
		block_y = all->coins->instances[i].y;
		player_x = (all->hero[0]->instances[0].x);
		player_y = all->hero[0]->instances[0].y;
		if ((((block_x - player_x) <= 20 && (block_x - player_x) >= -20))
			&& ((block_y - player_y) <= 20 && (block_y - player_y) >= -20))
		{
			if (all->coins->instances[i].enabled)
			{
				all->coins->instances[i].enabled = false;
				all->count_exit++;
			}
			return ;
		}
		i++;
	}
}
