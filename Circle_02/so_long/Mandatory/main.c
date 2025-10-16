/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:39:54 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 21:49:32 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char *av[])
{
	t_data	*source;
	t_map	*all;

	if (ac != 2)
		return (1);
	if (!ft_check_extension(av[1]))
		return (1);
	source = malloc(sizeof(t_data));
	if (!source)
		return (1);
	if (!ft_get_create_wind(av[1], source))
		return (1);
	all = malloc(sizeof(t_map));
	if (!all)
		return (1);
	all->mlx = mlx_init(source->width * 64, source->height * 64,
			"BOUSHTA O BOUGTAYA", false);
	if (all->mlx == NULL)
		return (1);
	load_main(all, source);
	ft_movement(all, source);
	ft_movement1(all, source);
	mlx_loop_hook(all->mlx, ft_function_key, all);
	mlx_loop(all->mlx);
	return (free_map(all), 0);
}
