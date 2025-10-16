/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:29 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 21:49:03 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include "/Users/risattou/Desktop/so1/MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_data
{
	char		**map;
	int			height;
	int			width;
	int			p;
	int			e;
	int			c;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	**hero;
	mlx_image_t	*the_wall;
	mlx_image_t	*purple_hole;
	mlx_image_t	*background;
	mlx_image_t	*coins;
	int			movement;
	int			nbr;
	int			sign;
	int			count_wall;
	int			count_coins;
	int			count_exit;
	int			time;
}				t_map;

int				check_map_valid(char **map);
t_point			find_player(char **map, t_data *source);
void			ft_error(void *str);
void			*ft_free(char **new, int index);
void			ft_check_wall(t_data *source);
int				ft_strchr1(const char *str, char c);
void			flood_fill(char **map, t_point size, t_point begin);
void			load_main(t_map *all, t_data *source);
void			ft_movement(t_map *all, t_data *source);
void			ft_movement1(t_map *all, t_data *source);
int				ft_check_up(t_map *all);
int				ft_check_down(t_map *all);
int				ft_check_left(t_map *all);
int				ft_check_right(t_map *all);
void			ft_check_coins(t_map *all);
int				ft_check_extension(char *filename);
int				ft_strlen_nl(const char *str);
int				ft_get_create_wind(char *filename, t_data *source);
void			ft_turn_off(t_map *all, int i, int j);
void			ft_function_key(void *param);
void			ft_steps(t_map *all, int x, int y);
void			free_map(t_map *map);

#endif