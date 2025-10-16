/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_function_key.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 19:28:24 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 21:51:39 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_close_window(t_map *all)
{
	int	char_x;
	int	char_y;
	int	hole_x;
	int	hole_y;

	char_x = all->hero[0]->instances[0].x;
	char_y = all->hero[0]->instances[0].y;
	hole_x = all->purple_hole->instances[0].x;
	hole_y = all->purple_hole->instances[0].y;
	if (((char_x - hole_x <= 20) && (char_y - hole_y <= 20) && (char_x
				- hole_x >= -20) && (char_y - hole_y >= -20))
		&& all->purple_hole->enabled)
		return (1);
	return (0);
}

void	ft_side_left_on(t_map *all)
{
	if (all->time < 2)
	{
		all->hero[1]->enabled = true;
		all->hero[0]->enabled = false;
		all->time++;
	}
	else if (all->time < 8)
	{
		all->hero[2]->enabled = true;
		all->hero[1]->enabled = false;
		all->time++;
	}
	else if (all->time < 14)
	{
		all->hero[3]->enabled = true;
		all->hero[2]->enabled = false;
		all->time++;
	}
	else
	{
		all->hero[0]->enabled = true;
		all->hero[3]->enabled = false;
		all->time = 0;
	}
}

void	ft_side_right_on(t_map *all)
{
	if (all->time < 2)
	{
		all->hero[5]->enabled = true;
		all->hero[4]->enabled = false;
		all->time++;
	}
	else if (all->time < 8)
	{
		all->hero[6]->enabled = true;
		all->hero[5]->enabled = false;
		all->time++;
	}
	else if (all->time < 14)
	{
		all->hero[7]->enabled = true;
		all->hero[6]->enabled = false;
		all->time++;
	}
	else
	{
		all->hero[4]->enabled = true;
		all->hero[7]->enabled = false;
		all->time = 0;
	}
}

static void	handle_key_movements(t_map *all)
{
	if (mlx_is_key_down(all->mlx, MLX_KEY_UP) || mlx_is_key_down(all->mlx,
			MLX_KEY_DOWN) || mlx_is_key_down(all->mlx, MLX_KEY_LEFT)
		|| mlx_is_key_down(all->mlx, MLX_KEY_RIGHT))
	{
		if (all->hero[0]->enabled)
			ft_side_left_on(all);
		if (all->hero[4]->enabled == true)
			ft_side_right_on(all);
		if (mlx_is_key_down(all->mlx, MLX_KEY_UP) && !ft_check_up(all))
			ft_steps(all, 0, -2);
		if (mlx_is_key_down(all->mlx, MLX_KEY_DOWN) && !ft_check_down(all))
			ft_steps(all, 0, 2);
		if (mlx_is_key_down(all->mlx, MLX_KEY_LEFT) && !ft_check_left(all))
			ft_steps(all, -2, 0);
		if (mlx_is_key_down(all->mlx, MLX_KEY_RIGHT) && !ft_check_right(all))
			ft_steps(all, 2, 0);
	}
}

void	ft_function_key(void *param)
{
	t_map	*all;

	all = (t_map *)param;
	handle_key_movements(all);
	if (all->movement > 0)
	{
		ft_check_coins(all);
		if (all->count_coins == all->count_exit)
			all->purple_hole->enabled = true;
		if (all->movement >= 32)
		{
			all->nbr++;
			ft_putnbr_fd(all->nbr, 1);
			write(1, "\n", 1);
			all->movement = 0;
		}
	}
	if (mlx_is_key_down(all->mlx, MLX_KEY_ESCAPE) || ft_close_window(all))
		mlx_close_window(all->mlx);
}
