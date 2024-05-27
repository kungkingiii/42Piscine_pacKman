/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/28 01:03:14 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/28 01:10:15 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

static void	check_error_xpm(t_data *data)
{
	if (!data->wall || !data->floor ||!data->player
		|| !data->collectible || !data->exit || !data->enemy)
	{
		ft_printf("ERROR:can't draw map");
		quit_game(data, 0);
	}
}

void	init_image(t_data *data)
{
	int	a;
	int	b;

	data->player = mlx_xpm_file_to_image(data->mlx,
			"../textures/player.xpm", &a, &b);
	data->collectible = mlx_xpm_file_to_image(data->mlx,
			"../textures/collectible.xpm", &a, &b);
	data->exit = mlx_xpm_file_to_image(data->mlx,
			"../textures/exit.xpm", &a, &b);
	data->floor = mlx_xpm_file_to_image(data->mlx,
			"../textures/floor.xpm", &a, &b);
	data->wall = mlx_xpm_file_to_image(data->mlx,
			"../textures/wall.xpm", &a, &b);
	data->enemy = mlx_xpm_file_to_image(data->mlx,
			"../textures/enemy.xpm", &a, &b);
	check_error_xpm(data);
}
