#include "../so_long.h"
 
void init_image(t_data *data)
{
    int a;
	int b;

    data->player = mlx_xpm_file_to_image(data->mlx,"../textures/player.xpm",&a,&b);
	data->collectible = mlx_xpm_file_to_image(data->mlx,"../textures/collectible.xpm",&a,&b); 
	data->exit = mlx_xpm_file_to_image(data->mlx,"../textures/exit.xpm",&a,&b);
	data->floor = mlx_xpm_file_to_image(data->mlx,"../textures/floor.xpm",&a,&b);
	data->wall = mlx_xpm_file_to_image(data->mlx,"../textures/wall.xpm",&a,&b);
	data->enemy = mlx_xpm_file_to_image(data->mlx,"../textures/enemy.xpm",&a,&b);
}
