/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:00:29 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 20:13:31 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	*ft_free(char **new, int index)
{
	while (index >= 0)
		free(new[index--]);
	free(new);
	return (NULL);
}

void	ft_error(void *str)
{
	if (str != NULL)
		free(str);
	ft_putstr_fd("Error\nMap_not valid\n", 1);
	exit(1);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	if (map->hero != NULL)
	{
		while (map->hero[i] != NULL)
		{
			mlx_delete_image(map->mlx, map->hero[i]);
			i++;
		}
		free(map->hero);
	}
	if (map->the_wall != NULL)
		mlx_delete_image(map->mlx, map->the_wall);
	if (map->purple_hole != NULL)
		mlx_delete_image(map->mlx, map->purple_hole);
	if (map->background != NULL)
		mlx_delete_image(map->mlx, map->background);
	if (map->coins != NULL)
		mlx_delete_image(map->mlx, map->coins);
	if (map->mlx != NULL)
		mlx_terminate(map->mlx);
	free(map);
}
