/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:15:39 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/28 22:48:58 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "lib/ft_printf.h"
# include "lib/libft.h"
# include <stdbool.h>
# include <fcntl.h>

# define WINSIZE 64

# define W 119
# define A 97
# define S 115
# define D 100

# define UP 65362
# define LEFT 65361
# define DOWN 65364
# define RIGHT 65363

# define ESC 65307
# define SP 32
# define KEY_X 53

typedef struct s_data
{
	void	*player;
	void	*exitp;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*mlx;
	int		pickcount;
	int		x;
	int		y;
	int		rows;
	int		cols;
	char	**map;
	int		moves;
	void	*window;
}		t_data;

void	detroy_all(t_data *data);
size_t	ft_c_arr_len(char **array);
t_data	*handle_input(char *filepath);
bool	check_map(char **map);
bool	check_path(char **map);
void	init_image(t_data *data);
void	draw_map(t_data *data);
int		quit_game(t_data *data, int exit_code);
void	handle_move(t_data *data, int col, int row);

#endif
