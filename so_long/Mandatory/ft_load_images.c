/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_load_images.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 12:07:32 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 15:15:06 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*create_path(char *base, int num)
{
	char	*path;
	int		i;

	path = malloc(ft_strlen(base) + 7);
	if (!path)
		return (NULL);
	i = 0;
	while (base[i])
	{
		path[i] = base[i];
		i++;
	}
	path[i++] = num / 10 + '0';
	path[i++] = num % 10 + '0';
	path[i++] = '.';
	path[i++] = 'p';
	path[i++] = 'n';
	path[i++] = 'g';
	path[i] = '\0';
	return (path);
}

static void	load_sequence(t_map *all, char *base_path)
{
	mlx_texture_t	*img;
	char			*path;
	int				i;

	i = 0;
	all->hero = malloc(8 * sizeof(mlx_image_t *));
	if (all->hero == NULL)
		exit(1);
	while (i <= 7)
	{
		path = create_path(base_path, i);
		if (!path)
			exit(1);
		img = mlx_load_png(path);
		free(path);
		if (img == NULL)
			exit(1);
		all->hero[i] = mlx_texture_to_image(all->mlx, img);
		mlx_delete_texture(img);
		mlx_resize_image(all->hero[i], 64, 64);
		i++;
	}
}

static void	load_img(t_map *all, t_data *source)
{
	mlx_texture_t	*backgrnd;
	mlx_texture_t	*wall;

	backgrnd = mlx_load_png("Mandatory/packages/image.png");
	if (backgrnd == NULL)
		exit(1);
	all->background = mlx_texture_to_image(all->mlx, backgrnd);
	mlx_delete_texture(backgrnd);
	mlx_resize_image(all->background, source->width * 64, source->height * 64);
	wall = mlx_load_png("Mandatory/packages/bg.png");
	if (wall == NULL)
		exit(1);
	all->the_wall = mlx_texture_to_image(all->mlx, wall);
	mlx_delete_texture(wall);
	mlx_resize_image(all->the_wall, 64, 64);
}

void	load_main(t_map *all, t_data *source)
{
	mlx_texture_t	*coins;
	mlx_texture_t	*purple;

	all->count_wall = 0;
	all->count_coins = 0;
	all->count_exit = 0;
	all->movement = 0;
	all->nbr = 0;
	all->time = 0;
	coins = mlx_load_png("Mandatory/packages/32.png");
	if (coins == NULL)
		exit(1);
	all->coins = mlx_texture_to_image(all->mlx, coins);
	mlx_delete_texture(coins);
	mlx_resize_image(all->coins, 48, 48);
	purple = mlx_load_png("Mandatory/players/PNG/char/Spells-Effect.png");
	if (purple == NULL)
		exit(1);
	all->purple_hole = mlx_texture_to_image(all->mlx, purple);
	mlx_delete_texture(purple);
	mlx_resize_image(all->purple_hole, 64, 64);
	load_img(all, source);
	load_sequence(all, "Mandatory/players/PNG/char/0");
}
