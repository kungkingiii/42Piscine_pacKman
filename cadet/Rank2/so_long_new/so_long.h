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
# define M_CLK_L 1
# define M_CLK_R 3
# define M_CLK_M 2
# define M_SCR_U 4
# define M_SCR_D 5

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
	void	*window;
}   t_data;

// typedef struct s_map_counts
// {
// 	int			fl_count;
// 	int			wall_count;
// 	int			col_count;
// }				t_map_counts;

void    detroy_all(t_data *data);
size_t	ft_c_arr_len(char **array);
t_data	*handle_input(char *filepath);
bool	check_map(char **map);
bool	check_path(char **map);
void	init_image(t_data *data);
void	draw_map(t_data *data);
int		quit_game(t_data *data, int exit_code);


#endif