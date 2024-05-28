/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:03:06 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/28 22:06:31 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	player_move(t_data *data, int i, int j)
{
	data->moves += 1;
	if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(
			data->mlx, data->window, data->exitp,
			WINSIZE * j, WINSIZE * i);
	}
	else
	{
		mlx_put_image_to_window(data->mlx, data->window, data->player,
			WINSIZE * j, WINSIZE * i);
	}
	data->x = j;
	data->y = i;
	ft_printf("\rmove count: %i", data->moves);
}

static void	which_tile(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		data->map[i][j] = '0';
		data->pickcount -= 1;
	}
	if (data->map[i][j] == 'E' && data->pickcount == 0)
	{
		ft_printf("\nYou beat it! win in %i moves\n", data->moves);
		quit_game(data, 1);
		return ;
	}
	player_move(data, i, j);
}

static void	update_floor(t_data *data)
{
	if (data->map[data->y][data->x] == 'E')
	{
		mlx_put_image_to_window(
			data->mlx, data->window, data->exit,
			WINSIZE * data->x, WINSIZE * data->y);
	}
	else
	{
		mlx_put_image_to_window(
			data->mlx, data->window, data->floor,
			WINSIZE * data->x, WINSIZE * data->y);
	}
}

void	handle_move(t_data *data, int col, int row)
{
	int	i;
	int	j;

	i = data->y + row;
	j = data->x + col;
	if (data->map[i][j] == '1')
		return ;
	update_floor(data);
	which_tile(data, i, j);
}
