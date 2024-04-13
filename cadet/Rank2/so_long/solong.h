/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solong.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/11 22:50:49 by packmanich        #+#    #+#             */
/*   Updated: 2024/04/13 11:43:56 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SOLONG_H
# define SOLONG_H

# include "MLX42/include/MLX42/MLX42.h"
# include "libft/libft.h"
# include <fcntl.h>

# define TILESIZE 64

typedef struct s_map
{
	char		**map;
	int			rows;
	int			cols;
	int			collectibles;
	int			collected;
	int			*c_x;
	int			*c_y;
	int			moves;
	mlx_image_t	*wall_img;
	mlx_image_t	*player_img;
	mlx_image_t	*exit_img;
	mlx_image_t	*collectible_img;
	mlx_image_t	*floor_img;
	mlx_t		*mlx;

}				t_map;

typedef struct s_draw_counts
{
	int			fl_count;
	int			wall_count;
	int			col_count;
}				t_draw_counts;

t_map			*handle_input(char *filepath);
bool			check_map(char **map);
bool			check_path(char **map);
t_map			*make_map(char *buffer);
void			init_images(t_map *map_data);
void			draw_map(t_map *map_data);
void			handle_move(int off_x, int off_y, t_map *map_data);
void			exit_routine(t_map *map_data);

#endif