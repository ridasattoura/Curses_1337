/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_extension_main.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/26 15:41:22 by risattou          #+#    #+#             */
/*   Updated: 2025/03/03 03:01:15 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	initial_read(int fd, t_data *source, char **tmp)
{
	char	*str;

	str = get_next_line(fd);
	if (!str)
		return (0);
	*tmp = ft_strdup(str);
	if (*tmp == NULL)
		return (0);
	free(str);
	source->height++;
	source->width = ft_strlen_nl(*tmp);
	return (1);
}

static int	process_lines(int fd, t_data *source, char **tmp)
{
	char	*str;
	char	*line;

	while (1)
	{
		str = get_next_line(fd);
		if (!str)
			break ;
		if (source->width != ft_strlen_nl(str))
			ft_error(str);
		line = ft_strjoin_gnl(*tmp, str);
		if (!line)
		{
			free(str);
			free(*tmp);
			*tmp = NULL;
			return (0);
		}
		free(*tmp);
		*tmp = line;
		source->height++;
		free(str);
		str = NULL;
	}
	return (1);
}

static int	read_and_process_file(int fd, t_data *source, char **tmp)
{
	if (!initial_read(fd, source, tmp))
		ft_error(source);
	return (process_lines(fd, source, tmp));
}

static int	validate_and_finalize_map(t_data *source, char *tmp)
{
	char	**tmp_map;
	t_point	pos_player;
	t_point	size;

	source->map = ft_split(tmp, '\n');
	tmp_map = ft_split(tmp, '\n');
	ft_check_wall(source);
	pos_player = find_player(source->map, source);
	size.x = source->width;
	size.y = source->height;
	flood_fill(tmp_map, size, pos_player);
	if (check_map_valid(tmp_map) || !(source->p == 1 && source->e == 1
			&& source->c > 0))
		ft_error(NULL);
	ft_free(tmp_map, source->height);
	free(tmp);
	return (1);
}

int	ft_get_create_wind(char *filename, t_data *source)
{
	int		fd;
	char	*tmp;

	source->p = 0;
	source->c = 0;
	source->e = 0;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
		ft_error(source);
	if (!read_and_process_file(fd, source, &tmp))
		return (0);
	close(fd);
	return (validate_and_finalize_map(source, tmp));
}
