/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:39:42 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/17 19:19:49 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	init_enemy_images(t_map *map_data)
{
	mlx_texture_t	*enemy_texture_1;

	enemy_texture_1 = mlx_load_png("./textures/enemy3.png");
	map_data->enemy_image_1 = mlx_texture_to_image(map_data->mlx,
			enemy_texture_1);
	mlx_delete_texture(enemy_texture_1);
}

void	init_textures_and_images(t_map *map_data)
{
	mlx_texture_t	*wall_texture;
	mlx_texture_t	*player_texture;
	mlx_texture_t	*exit_texture;
	mlx_texture_t	*collectible_texture;
	mlx_texture_t	*floor_texture;

	wall_texture = mlx_load_png("./textures/wall.png");
	player_texture = mlx_load_png("./textures/player.png");
	exit_texture = mlx_load_png("./textures/exit.png");
	collectible_texture = mlx_load_png("./textures/collectible.png");
	floor_texture = mlx_load_png("./textures/floor.png");
	map_data->wall_image = mlx_texture_to_image(map_data->mlx, wall_texture);
	map_data->player_image = mlx_texture_to_image(map_data->mlx,
			player_texture);
	map_data->exit_image = mlx_texture_to_image(map_data->mlx, exit_texture);
	map_data->collectible_image = mlx_texture_to_image(map_data->mlx,
			collectible_texture);
	map_data->floor_image = mlx_texture_to_image(map_data->mlx, floor_texture);
	mlx_delete_texture(wall_texture);
	mlx_delete_texture(player_texture);
	mlx_delete_texture(exit_texture);
	mlx_delete_texture(collectible_texture);
	mlx_delete_texture(floor_texture);
	init_enemy_images(map_data);
}
