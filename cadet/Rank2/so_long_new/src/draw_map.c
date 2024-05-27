/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:02:50 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/28 01:06:28 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	draw_w_f(t_data *data, int i, int j)
{
	if (data->map[i][j] == '1')
	{
		mlx_put_image_to_window(data->mlx,
			data->window, data->wall, j * WINSIZE, i * WINSIZE);
	}
	else if (data->map[i][j] == '0')
	{
		mlx_put_image_to_window(data->mlx,
			data->window, data->floor, j * WINSIZE, i * WINSIZE);
	}
}

static void	draw_p_e(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'P')
	{
		mlx_put_image_to_window(data->mlx,
			data->window, data->player, j * WINSIZE, i * WINSIZE);
		data->x = j;
		data->y = i;
	}
	if (data->map[i][j] == 'E')
	{
		mlx_put_image_to_window(data->mlx,
			data->window, data->exit, j * WINSIZE, i * WINSIZE);
	}
}

static void	draw_c(t_data *data, int i, int j)
{
	if (data->map[i][j] == 'C')
	{
		mlx_put_image_to_window(data->mlx,
			data->window, data->collectible, j * WINSIZE, i * WINSIZE);
		data->pickcount++;
	}
}

void	draw_map(t_data *data)
{
	int				i;
	int				j;

	data->pickcount = 0;
	i = 0;
	while (data->map[i])
	{
		j = 0;
		while (data->map[i][j])
		{
			draw_w_f(data, i, j);
			draw_p_e(data, i, j);
			draw_c(data, i, j);
			j++;
		}
		i++;
	}
}
