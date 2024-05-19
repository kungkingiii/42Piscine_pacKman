#include "includes/so_long.h"

static void	free_map(t_mlx_data *game)
{
	int	i;

	i = 0;
	if (game->map)
	{
		while (game->map[i])
		{
			free(game->map[i]);
			i++;
		}
		free(game->map);
	}
}

static void	free_img(t_mlx_data *game)
{
	if (game->floor)
		mlx_destroy_image(game->mlx_ptr, game->floor);
	if (game->wall)
		mlx_destroy_image(game->mlx_ptr, game->wall);
	if (game->player)
		mlx_destroy_image(game->mlx_ptr, game->player);
	if (game->exit)
		mlx_destroy_image(game->mlx_ptr, game->exit);
	if (game->collectable)
		mlx_destroy_image(game->mlx_ptr, game->collectable);
}

int	quit_game(t_mlx_data *game, int exit_code)
{
	if (!game)
		return (0);
	if (game->win_ptr)
		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	free_img(game);
	if (game->mlx_ptr)
	{
		mlx_destroy_display(game->mlx_ptr);
		free(game->mlx_ptr);
	}
	if (game->img_ptr)
		free(game->img_ptr);
	free_map(game);
	exit(exit_code);
}

void	notify(t_mlx_data *game, char *error_msg)
{
	int	exit_code;

	exit_code = 0;
	if (error_msg)
		exit_code = 1;
	ft_putstr_fd("Error: ", STDERR_FILENO);
	ft_putendl_fd(error_msg, STDERR_FILENO);
	quit_game(game, exit_code);
}

/* set_start is start use a minilibx by funtion mlx_init*/
void	set_start(t_mlx_data *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		notify(game, MLX_INIT_ERR);
}
