/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_image_to_window.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 14:57:59 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 15:50:59 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_movement(t_map *all, t_data *source)
{
	int	y;
	int	x;

	y = 0;
	mlx_image_to_window(all->mlx, all->background, 0, 0);
	while (y < source->height)
	{
		x = 0;
		while (x < source->width)
		{
			if (source->map[y][x] == '1')
			{
				mlx_image_to_window(all->mlx, all->the_wall, x * 64, y * 64);
				all->count_wall++;
			}
			else if (source->map[y][x] == 'E')
			{
				mlx_image_to_window(all->mlx, all->purple_hole, x * 64, y * 64);
				all->purple_hole->enabled = false;
			}
			x++;
		}
		y++;
	}
}

void	image_put_window(t_map *all, int x, int y)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		mlx_image_to_window(all->mlx, all->hero[i], x * 64, y * 64);
		i++;
	}
	i = 1;
	while (i < 8)
	{
		all->hero[i]->enabled = false;
		i++;
	}
}

void	ft_movement1(t_map *all, t_data *source)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (y < source->height)
	{
		x = 0;
		while (x < source->width)
		{
			if (source->map[y][x] == 'P')
				image_put_window(all, x, y);
			else if (source->map[y][x] == 'C')
			{
				mlx_image_to_window(all->mlx, all->coins, x * 64, y * 64);
				all->count_coins++;
			}
			x++;
		}
		y++;
	}
	ft_free(source->map, source->height);
	free(source);
}

void	ft_turn_img(mlx_image_t **character, int i)
{
	int	index;

	if (i > 0)
	{
		index = 4;
		while (index < 8)
			character[index++]->enabled = false;
		character[0]->enabled = true;
	}
	else
	{
		index = 0;
		while (index < 4)
			character[index++]->enabled = false;
		character[4]->enabled = true;
	}
}

void	ft_turn_off(t_map *all, int i, int j)
{
	if (j)
		ft_turn_img(all->hero, i);
}
