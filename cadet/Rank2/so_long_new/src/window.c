#include "../so_long.h"

static void	free_map(t_data *data)
{
	int	i;

	i = 0;
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
}

void detroy_all(t_data *data)
{
    if (data->player)
			mlx_destroy_image(data->mlx, data->player);
    if (data->wall)
			mlx_destroy_image(data->mlx, data->wall);
    if (data->floor)
			mlx_destroy_image(data->mlx, data->floor);
    if (data->exit)
			mlx_destroy_image(data->mlx, data->exit);
    if (data->collectible)
			mlx_destroy_image(data->mlx, data->collectible);
	if (data->enemy)
			mlx_destroy_image(data->mlx, data->enemy);
	if (data->window)
		mlx_destroy_window(data->mlx, data->window);
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}

int	quit_game(t_data *data, int exit_code)
{
	if (!data)
		return (0);
	detroy_all(data);
	free_map(data);
	exit(exit_code);
}