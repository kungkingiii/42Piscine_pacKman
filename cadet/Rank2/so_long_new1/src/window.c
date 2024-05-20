#include "so_long.h"

void detroy_all(t_data *data)
{
    if (data->img1)
	{
			mlx_destroy_image(data->mlx, data->img1);
	}
	if (data->img2)
	{
			mlx_destroy_image(data->mlx, data->img2);
	}
	if (data->window)
	{
		mlx_destroy_window(data->mlx, data->window);
	}
	
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		free(data->mlx);
	}
	exit(1);
}
