/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_enemy_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/13 14:08:06 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 12:27:08 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_player_collision(t_map *all)
{
	int	enemy_x;
	int	enemy_y;
	int	player_x;
	int	player_y;

	enemy_x = all->enemy[0]->instances[0].x;
	enemy_y = all->enemy[0]->instances[0].y;
	player_x = all->hero[0]->instances[0].x;
	player_y = all->hero[0]->instances[0].y;
	if (((enemy_x - player_x) < 10 && (enemy_x - player_x) > -10) && ((enemy_y
				- player_y) < 10 && (enemy_y - player_y) > -10))
	{
		return (1);
	}
	return (0);
}

void	ft_start_enemy_diagonal(t_map *all)
{
	int	dx;
	int	dy;
	int	move_x;
	int	move_y;

	dx = all->hero[0]->instances[0].x - all->enemy[0]->instances[0].x;
	dy = all->hero[0]->instances[0].y - all->enemy[0]->instances[0].y;
	move_x = 0;
	move_y = 0;
	if (dx > 0 && !ft_check_enemy_right(all))
		move_x = 2;
	else if (dx < 0 && !ft_check_enemy_left(all))
		move_x = -2;
	if (dy > 0 && !ft_check_enemy_down(all))
		move_y = 2;
	else if (dy < 0 && !ft_check_enemy_up(all))
		move_y = -2;
	if (move_x != 0 || move_y != 0)
		ft_steps_enemy(all, move_x, move_y);
	if (ft_check_player_collision(all))
		mlx_close_window(all->mlx);
}

void	ft_turn_off(t_map *all, int i, int j)
{
	if (j)
		ft_turn_img(all->hero, i);
	else
		ft_turn_img(all->enemy, i);
}
