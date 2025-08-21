/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:00:29 by risattou          #+#    #+#             */
/*   Updated: 2025/03/11 03:23:55 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

void	display_number(t_map *all)
{
	char	*nbr;
	char	*str;

	nbr = ft_itoa(all->nbr);
	str = ft_strjoin("MOVEMENT PLAYER :", nbr);
	if (all->text_img != NULL)
		mlx_delete_image(all->mlx, all->text_img);
	all->text_img = mlx_put_string(all->mlx, str, 20, 20);
	if (!all->text_img)
		exit(1);
	free(str);
	free(nbr);
	str = NULL;
	nbr = NULL;
}

static void	ft_help1(mlx_t *mlx, mlx_image_t **remove)
{
	int	i;

	i = 0;
	while (remove[i] != NULL)
	{
		mlx_delete_image(mlx, remove[i]);
		i++;
	}
	free(remove);
}

void	free_map(t_map *map)
{
	int	i;

	i = 0;
	if (map == NULL)
		return ;
	if (map->hero != NULL)
		ft_help1(map->mlx, map->hero);
	if (map->enemy != NULL)
		ft_help1(map->mlx, map->enemy);
	if (map->the_wall != NULL)
		mlx_delete_image(map->mlx, map->the_wall);
	if (map->purple_hole != NULL)
		mlx_delete_image(map->mlx, map->purple_hole);
	if (map->background != NULL)
		mlx_delete_image(map->mlx, map->background);
	if (map->coins != NULL)
		mlx_delete_image(map->mlx, map->coins);
	if (map->text_img != NULL)
		mlx_delete_image(map->mlx, map->text_img);
	free(map);
}
