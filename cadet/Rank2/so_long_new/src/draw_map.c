#include "../so_long.h"

static void	draw_w_f(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
	{
        mlx_put_image_to_window(data->mlx,data->window,data->wall,j * WINSIZE, i * WINSIZE);
		// mlx_image_to_window(data->mlx,
		// 	data->wall_image, j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth
		// 	(&(data->wall_image->instances[(*counts).wall_count++]), 0);
	}
	else if (data->map[i][j] == '0')
	{
		mlx_put_image_to_window(data->mlx,data->window,data->floor,j * WINSIZE, i * WINSIZE);
		
		// mlx_set_instance_depth
		// 	(&(data->floor_image->instances[(*counts).fl_count++]), 1);
	}
}

static void	draw_p_e(t_data *data, int i, int j)
// static void	draw_p_e(t_data *data, int i, int j, t_map_counts *counts)
{
	if (data->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx,data->window,data->floor,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth
		// 	(&(data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_put_image_to_window(data->mlx,data->window,data->player,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth(&(data->player_image->instances[0]), 3);
	}
	if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx,data->window,data->floor,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth
		// 	(&(data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_put_image_to_window(data->mlx,data->window,data->exit,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth(&(data->exit_image->instances[0]), 2);
	}
}

static void	draw_c(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx,data->window,data->floor,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth
		// 	(&(data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_put_image_to_window(data->mlx,data->window,data->collectible,j * WINSIZE, i * WINSIZE);
		// mlx_set_instance_depth
		// 	(&(data->collectible_image->instances[(*counts).col_count++]),
		// 		2);
	}
}

void	draw_map(t_data *data)
{
	int				i;
	int				j;
	// t_map_counts	counts;

	i = 0;
	// counts.wall_count = 0;
	// counts.fl_count = 0;
	// counts.col_count = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_w_f(data, i, j);
			draw_p_e(data, i, j);
			draw_c(data, i, j);
			// draw_w_f(data, i, j, &counts);
			// draw_p_e(data, i, j, &counts);
			// draw_c(data, i, j, &counts);
			j++;
		}
		i++;
	}
}
