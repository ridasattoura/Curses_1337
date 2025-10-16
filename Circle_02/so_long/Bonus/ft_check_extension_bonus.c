/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 15:32:27 by risattou          #+#    #+#             */
/*   Updated: 2025/03/06 16:05:22 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	ft_check_extension(char *filename)
{
	int	len;

	len = ft_strlen(filename) - 4;
	filename += len;
	if (ft_strncmp(filename, ".ber", 4) == 0)
		return (1);
	return (0);
}

int	ft_strlen_nl(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0' && str[i] != '\n')
	{
		if (!ft_strchr1("EPFC01", str[i]))
			ft_error(NULL);
		i++;
	}
	return (i);
}

static void	ft_valid_valid(char c, t_data *source)
{
	if (c == 'F')
		source->f++;
	else if (c == 'C')
		source->c++;
	else if (c == 'E')
		source->e++;
}

t_point	find_player(char **map, t_data *source)
{
	int		i;
	int		j;
	t_point	start;

	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'P')
			{
				start.y = i;
				start.x = j;
				source->p++;
			}
			ft_valid_valid(map[i][j], source);
			j++;
		}
		i++;
	}
	return (start);
}

int	check_map_valid(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (ft_strchr1("PCEF", map[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
