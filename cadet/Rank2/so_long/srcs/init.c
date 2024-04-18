/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:39:42 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/18 14:24:03 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	init_textures_and_images(t_map *map_data)
{
	map_data->wall_texture = mlx_load_png("./textures/wall.png");
	map_data->player_texture = mlx_load_png("./textures/player.png");
	map_data->exit_texture = mlx_load_png("./textures/exit.png");
	map_data->collectible_texture = mlx_load_png("./textures/collectible.png");
	map_data->floor_texture = mlx_load_png("./textures/floor.png");
	map_data->wall_image = mlx_texture_to_image(map_data->mlx,
			map_data->wall_texture);
	map_data->player_image = mlx_texture_to_image(map_data->mlx,
			map_data->player_texture);
	map_data->exit_image = mlx_texture_to_image(map_data->mlx,
			map_data->exit_texture);
	map_data->collectible_image = mlx_texture_to_image(map_data->mlx,
			map_data->collectible_texture);
	map_data->floor_image = mlx_texture_to_image(map_data->mlx,
			map_data->floor_texture);
}

static void	draw_w_f(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == '1')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->wall_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->wall_image->instances[(*counts).wall_count++]), 0);
	}
	else if (map_data->map[i][j] == '0')
	{
		mlx_image_to_window
			(map_data->mlx, map_data->floor_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_image->instances[(*counts).fl_count++]), 1);
	}
}

static void	draw_p_e(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == 'P')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->floor_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window(map_data->mlx,
			map_data->player_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth(&(map_data->player_image->instances[0]), 3);
	}
	if (map_data->map[i][j] == 'E')
	{
		mlx_image_to_window(map_data->mlx,
			map_data->floor_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window(map_data->mlx,
			map_data->exit_image, j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth(&(map_data->exit_image->instances[0]), 2);
	}
}

static void	draw_c(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	if (map_data->map[i][j] == 'C')
	{
		mlx_image_to_window(map_data->mlx, map_data->floor_image,
			j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->floor_image->instances[(*counts).fl_count++]), 1);
		mlx_image_to_window
			(map_data->mlx, map_data->collectible_image,
			j * TILESIZE, i * TILESIZE);
		mlx_set_instance_depth
			(&(map_data->collectible_image->instances[(*counts).col_count++]),
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
