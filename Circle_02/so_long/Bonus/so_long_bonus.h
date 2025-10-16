/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/06 16:04:29 by risattou          #+#    #+#             */
/*   Updated: 2025/03/10 20:15:53 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "/Users/risattou/Desktop/so1/MLX42/include/MLX42/MLX42.h"
# include "../libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

typedef struct s_data
{
	char		**map;
	int			height;
	int			width;
	int			p;
	int			e;
	int			c;
	int			f;
}				t_data;

typedef struct s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct s_map
{
	mlx_t		*mlx;
	mlx_image_t	*the_wall;
	mlx_image_t	**enemy;
	mlx_image_t	**hero;
	mlx_image_t	*purple_hole;
	mlx_image_t	*background;
	mlx_image_t	*coins;
	mlx_image_t	*text_img;
	int			movement;
	int			nbr;
	int			sign;
	int			count_wall;
	int			count_coins;
	int			count_exit;
	int			time;
}				t_map;

void			display_number(t_map *all);
int				check_map_valid(char **map);
t_point			find_player(char **map, t_data *source);
void			ft_error(void *str);
void			*ft_free(char **new_, int index);
void			ft_check_wall(t_data *source);
int				ft_strchr1(const char *str, char c);
void			flood_fill(char **map, t_point size, t_point begin);
void			ft_turn_img(mlx_image_t **character, int i);
void			load_main(t_map *all, t_data *source);
void			ft_movement(t_map *all, t_data *source);
void			ft_movement1(t_map *all, t_data *source);
int				ft_check_up(t_map *all);
int				ft_check_down(t_map *all);
int				ft_check_left(t_map *all);
int				ft_check_right(t_map *all);
int				ft_check_enemy_up(t_map *all);
int				ft_check_enemy_down(t_map *all);
int				ft_check_enemy_left(t_map *all);
int				ft_check_enemy_right(t_map *all);
void			ft_check_coins(t_map *all);
void			ft_side_enemy_right_on(t_map *all);
void			ft_side_enemy_left_on(t_map *all);
int				ft_check_extension(char *filename);
int				ft_strlen_nl(const char *str);
int				ft_get_create_wind(char *filename, t_data *source);
void			ft_turn_off(t_map *all, int i, int j);
void			ft_function_key(void *param);
void			ft_steps(t_map *all, int x, int y);
void			ft_steps_enemy(t_map *all, int x, int y);
void			ft_start_enemy_diagonal(t_map *all);
void			free_map(t_map *map);

#endif