#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "lib/ft_printf.h"
# include "lib/libft.h"
# include <stdbool.h>
# include <fcntl.h>

# define WINSIZE 64

typedef struct	s_data {

	void	*player;
	void	*enemy;
	void	*collectible;
	void	*exit;
	void	*floor;
	void	*wall;
	void	*mlx;
	int				*c_x;
	int				*c_y;
	int				rows;
	int				cols;
	char			**map;
	int				collectibles;
	int				collected;
	int				moves;
	char	*addr;
	int		line_length;
	void	*window;
	int		bits_per_pixel;
}   t_data;

typedef struct s_map_counts
{
	int			fl_count;
	int			wall_count;
	int			col_count;
}				t_map_counts;

void    detroy_all(t_data *data);
size_t	ft_c_arr_len(char **array);
t_data	*handle_input(char *filepath);
bool	check_map(char **map);
bool	check_path(char **map);
void	init_image(t_data *data);
void	draw_map(t_data *data);


#endif