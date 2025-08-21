/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_steps_x_y_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 15:50:34 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 21:54:53 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	ft_steps(t_map *all, int x, int y)
{
	int	i;

	i = 0;
	all->movement += 1;
	if (x != 0)
		ft_turn_off(all, x, 1);
	while (i < 8)
	{
		all->hero[i]->instances[0].x += x;
		all->hero[i]->instances[0].y += y;
		i++;
	}
}

// void	ft_steps_enemy(t_map *all, int x, int y)
// {
// 	mlx_image_t **images[] = {
// 		all->enemy, &all->enemy1, &all->enemy2, &all->enemy3,
// 			&all->enemy4, &all->enemy5, &all->enemy6,
// 			&all->enemy7, &all->enemy0, &all->enemy01,
// 			&all->enemy02, &all->enemy03, &all->enemy04,
// 			&all->enemy05, &all->enemy06, &all->enemy07};
// 	int i = 0;
// 	while(i < 16)
// 	{
// 		if(x == 2)
// 		{puts("2x");}
// 		else if(y == 2)
// 		{puts("2y");}
// 		else if(x == -2)
// 		{puts("-2x");}
// 		else if(y == -2)
// 		{puts("-2y");}
// 		(*images[i])->instances[0].x += x;
// 		(*images[i])->instances[0].y += y;
// 		i++;
// 	}
// }
// void ft_steps_enemy(t_map *all, int x, int y) {
//     mlx_image_t **images[] = {
//         &all->enemy, &all->enemy1, &all->enemy2, &all->enemy3,
//         &all->enemy4, &all->enemy5, &all->enemy6, &all->enemy7,
//         &all->enemy0, &all->enemy01, &all->enemy02, &all->enemy03,
//         &all->enemy04, &all->enemy05, &all->enemy06, &all->enemy07
//     };

//     // Check for collision before moving
//     bool can_move = true; // Implement collision detection here if needed

//     if (can_move) {
//         for (int i = 0; i < 16; i++) {
//             (*images[i])->instances[0].x += x;
//             (*images[i])->instances[0].y += y;
//         }
//     }
// }