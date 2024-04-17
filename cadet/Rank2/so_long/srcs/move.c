/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 17:07:37 by chongsen          #+#    #+#             */
/*   Updated: 2024/04/17 19:01:10 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

static void	move_if_not_wall(int off_x, int off_y, t_map *map_data)
{
	int		x;
	int		y;
	char	*strmove;
	char	*str;
	bool	iswall;

	x = map_data->player_image->instances[0].x / TILESIZE + off_x;
	y = map_data->player_image->instances[0].y / TILESIZE + off_y;
	iswall = false;
	if (map_data->map[y][x] == '1')
		iswall = true;
	if (!iswall)
	{
		map_data->player_image->instances[0].x += (TILESIZE * off_x);
		map_data->player_image->instances[0].y += (TILESIZE * off_y);
		map_data->moves++;
		strmove = ft_itoa(map_data->moves);
		if (!strmove)
			free(strmove);
		str = ft_strjoin(strmove, "move");
		if (!str)
			free(strmove);
		map_data->mlx_i = mlx_put_string(map_data->mlx, str, 0, 0);
		ft_printf("\rMoves: %d ", map_data->moves);
	}
}

static void	check_endgame(t_map *map_data)
{
	int		x;
	int		y;
	bool	isexit;

	x = map_data->player_image->instances[0].x / TILESIZE;
	y = map_data->player_image->instances[0].y / TILESIZE;
	isexit = false;
	if (map_data->map[y][x] == 'E')
		isexit = true;
	if (isexit && map_data->collected == map_data->collectibles)
	{
		ft_printf("\nYou win in %d moves !\n", map_data->moves);
		exit_routine(map_data);
	}
}

static void	check_touch_enemy(t_map *map_data)
{
	int		x;
	int		y;
	int		ex;
	int		ey;
	bool	islose;

	x = map_data->player_image->instances[0].x / TILESIZE;
	y = map_data->player_image->instances[0].y / TILESIZE;
	ex = map_data->enemy_image_1->instances[0].x / TILESIZE;
	ey = map_data->enemy_image_1->instances[0].y / TILESIZE;
	islose = false;
	if (ex == x && ey == y)
		islose = true;
	if (islose)
	{
		ft_printf("\nYou Lose because touch enemy!!!!\n", map_data->moves);
		exit_routine(map_data);
	}
}

static void	collect(int collectible_index, t_map *map_data)
{
	map_data->collected++;
	mlx_set_instance_depth
		(&(map_data->collectible_image->instances[collectible_index]), 0);
}

static void	handle_collectible(t_map *map_data)
{
	int	collectible_index;
	int	i;
	int	x;
	int	y;

	collectible_index = -1;
	i = 0;
	x = map_data->player_image->instances[0].x / TILESIZE;
	y = map_data->player_image->instances[0].y / TILESIZE;
	while (i < map_data->collectibles)
	{
		if (x == map_data->c_x[i]
			&& y == map_data->c_y[i])
			collectible_index = i;
		i++;
	}
	if (collectible_index != -1)
	{
		if (map_data->collectible_image->instances[collectible_index].z == 2)
			collect(collectible_index, map_data);
	}
}

void	handle_move(int off_x, int off_y, t_map *map_data)
{
	move_if_not_wall(off_x, off_y, map_data);
	handle_collectible(map_data);
	check_endgame(map_data);
	check_touch_enemy(map_data);
}
