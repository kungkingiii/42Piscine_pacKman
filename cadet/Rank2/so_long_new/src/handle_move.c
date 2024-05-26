#include "../so_long.h"

static void	player_move(t_data *data,int i, int j)
{
	data->moves += 1;
	mlx_put_image_to_window(data->mlx, data->window, data->player,
		WINSIZE * j, WINSIZE * i);
	data->x = j;
	data->y = i;
	ft_printf("move count: %i\n", data->moves);
}

static void	which_tile(t_data *data)
{
	if (data->map[data->y][data->x] == 'C')
	{
		data->map[data->y][data->x] = '0';
		data->pickcount -= 1;
		return ;
	}
	if (data->map[data->y][data->x] == 'E'
		&& data->pickcount == 0)
	{
		ft_printf("You Found the EXIT!!!!\n");
		quit_game(data, 1);
	}
}

static void	update_floor(t_data *data)
{
	// if (data->map[data->y][data->x] == 'E')
	// {
	// 	mlx_put_image_to_window(
	// 		data->mlx, data->window, data->exit,
	// 		WINSIZE * data->x,
	// 		WINSIZE * data->y);
	// }
	// else
	mlx_put_image_to_window(
		data->mlx, data->window, data->floor,
		WINSIZE * data->x, WINSIZE * data->y);
}

void	handle_move(t_data *data, int col, int row)
{
	int i;
	int j;

	i = data->y + row;
	j = data->x + col;
	if (data->map[i][j] == '1')
		return;
	update_floor(data);
	// data->x += len;
	
	which_tile(data);
	player_move(data, i, j);
}