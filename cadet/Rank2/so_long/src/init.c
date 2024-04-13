/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:39:42 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/13 11:27:36 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"


void	init_images(t_map *map_data)
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*floor_texture;

	wall_texture = mlx_load_png("./wall.png");
	player_texture = mlx_load_png("./player.png");
	exit_texture = mlx_load_png("./exit.png");
	collectible_texture = mlx_load_png("./collectible.png");
	floor_texture = mlx_load_png("./floor.png");
	map_data->wall_img = mlx_texture_to_image(map_data->mlx, wall_texture);
	map_data->player_img = mlx_texture_to_image(map_data->mlx,
			player_texture);
	map_data->exit_img = mlx_texture_to_image(map_data->mlx, exit_texture);
	map_data->collectible_img = mlx_texture_to_image(map_data->mlx,
			collectible_texture);
	map_data->floor_img = mlx_texture_to_image(map_data->mlx, floor_texture);
	mlx_delete_texture(wall_texture);
	mlx_delete_texture(player_texture);
	mlx_delete_texture(exit_texture);
	mlx_delete_texture(collectible_texture);
	mlx_delete_texture(floor_texture);
}

static void	draw_w_f(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == '1')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->wall_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->wall_img->instances[(*counts).wall_count++]), 0);
	}
	else if (map_data->map[i][j] == '0')
	{
		mlx_image_to_window
			(map_data->mlx, map_data->floor_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_img->instances[(*counts).fl_count++]), 1);
	}
}

static void	draw_p_e(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == 'P')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->floor_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_img->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window(map_data->mlx,
			map_data->player_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth(&(map_data->player_img->instances[0]), 3);
	}
	if (map_data->map[i][j] == 'E')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->floor_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_img->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window(map_data->mlx,
			map_data->exit_img, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth(&(map_data->exit_img->instances[0]), 2);
	}
}

static void	draw_c(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == 'C')
	{
		mlx_image_to_window(map_data->mlx, map_data->floor_img,
			j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_img->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window
			(map_data->mlx, map_data->collectible_img,
			j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->collectible_img->instances[(*counts).col_count++]),
				2);
	}
}

void	draw_map(t_map *map_data)
{
	int				i;
	int				j;
	t_draw_counts	counts;

	i = 0;
	counts.wall_count = 0;
	counts.fl_count = 0;
	counts.col_count = 0;
	while (map_data->map[i])
	{
		j = 0;
		while (map_data->map[i][j])
		{
			draw_w_f(map_data, i, j, &counts);
			draw_p_e(map_data, i, j, &counts);
			draw_c(map_data, i, j, &counts);
			j++;
		}
		i++;
	}
}
