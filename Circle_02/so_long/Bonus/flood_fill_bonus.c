/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 11:52:32 by risattou          #+#    #+#             */
/*   Updated: 2025/02/27 11:32:19 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_strchr1(const char *str, char c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	ff(char **map, t_point size, t_point begin, char *str)
{
	if (begin.y < 0 || begin.y >= size.y)
		return ;
	if (begin.x < 0 || begin.x >= size.x)
		return ;
	if (!ft_strchr1(str, map[begin.y][begin.x]))
		return ;
	map[begin.y][begin.x] = '2';
	ff(map, size, (t_point){begin.x + 1, begin.y}, str);
	ff(map, size, (t_point){begin.x - 1, begin.y}, str);
	ff(map, size, (t_point){begin.x, begin.y + 1}, str);
	ff(map, size, (t_point){begin.x, begin.y - 1}, str);
}

void	flood_fill(char **map, t_point size, t_point begin)
{
	char	*str;

	if (begin.y < 0 || begin.y >= size.y)
		return ;
	if (begin.x < 0 || begin.x >= size.x)
		return ;
	str = "ECPF0";
	ff(map, size, begin, str);
}
