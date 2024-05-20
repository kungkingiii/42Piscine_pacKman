#ifndef SO_LONG_H
# define SO_LONG_H

// # include "minilibx-linux/mlx.h"
// # include "minilibx-linux/mlx_int.h"
# include "mlx/mlx.h"
// # include "mlx/mlx_int.h"
# include "lib/ft_printf.h"
# include "lib/libft.h"
# include <fcntl.h>

typedef struct	s_data {
	void	*img1;
	void	*img2;
	void	*mlx;
	char	*addr;
	int		line_length;
	void	*window;
	int		bits_per_pixel;
}   t_data;

void    detroy_all(t_data *data);

#endif