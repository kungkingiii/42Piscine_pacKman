#include "includes/so_long.h"

static void	free_grid(char **grid)
{
	int	i;

	i = 0;
	if (grid)
	{
		while (grid[i])
		{
			free(grid[i]);
			i++;
		}
		free(grid);
	}
}

static char	**blank_grid(t_mlx_data *game)
{
	int		i;
	char	**grid;

	i = 0;
	grid = ft_calloc((game->heightmap + 1), sizeof(char *));
	if (!grid)
	{
		ft_printf("Error\n Memory allocation failed");
		quit_game(game, 1);
	}
	while (i < game->heightmap)
	{
		grid[i] = ft_strdup(game->map[i]);
		if (!grid[i])
		{
			ft_printf("Error\n Memory allocation failed");
			free_grid(grid);
			quit_game(game, 1);
		}
		i += 1;
	}
	return (grid);
}

static bool	flood_fill(t_mlx_data *game, t_point curr, char **sol_grid)
{
	static int		coins = 0;
	static bool		found_exit = false;

	if (sol_grid[curr.y][curr.x] == WALL)
		return (false);
	else if (sol_grid[curr.y][curr.x] == COLLECTIBLE)
		coins += 1;
	else if (sol_grid[curr.y][curr.x] == EXIT)
		found_exit = true;
	sol_grid[curr.y][curr.x] = WALL;
	flood_fill(game, (t_point){curr.x + 1, curr.y}, sol_grid);
	flood_fill(game, (t_point){curr.x - 1, curr.y}, sol_grid);
	flood_fill(game, (t_point){curr.x, curr.y + 1}, sol_grid);
	flood_fill(game, (t_point){curr.x, curr.y - 1}, sol_grid);
	return (coins == game->colleccount && found_exit);
}

void	check_path(t_mlx_data *game)
{
	char	**solong_grid;

	solong_grid = blank_grid(game);
	if (!flood_fill(game, game->player_pos, solong_grid))
	{
		ft_printf("Error\n Can't find exit path");
		free_grid(solong_grid);
		quit_game(game, 1);
	}
	free_grid(solong_grid);
	return ;
}
