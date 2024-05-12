/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/17 19:18:48 by chongsen          #+#    #+#             */
/*   Updated: 2024/05/12 19:24:50 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

// static int	draw_enemy(t_map *map_data, int i, int j)
// {
// 	int	im;
// 	int	jm;

// 	im = i;
// 	jm = j;
// 	if ((map_data->map[im + 1][jm] != 'E' && map_data->map[im + 1][jm] != 'P')
// 	&& (map_data->map[im - 1][jm] != 'E' && map_data->map[im - 1][jm] != 'P')
// 	&& (map_data->map[im][jm + 1] != 'E' && map_data->map[im][jm + 1] != 'P')
// 	&& (map_data->map[im][jm - 1] != 'E' && map_data->map[im][jm - 1] != 'P')
// 	)
// 	{
// 		if ((map_data->map[im + 1][jm] != '1'
// 			&& map_data->map[im + 1][jm] != '1'))
// 		{
// 			mlx_image_to_window
// 			(map_data->mlx, map_data->enemy_image_1,
// 			jm * TILESIZE, im * TILESIZE);
// 			mlx_set_instance_depth(&(map_data->enemy_image_1->instances[0]), 2);
// 			return (1);
// 		}
// 	}
// 	return (0);
// }

static void	draw_w_f(t_map *map_data, int i, int j, t_draw_counts *counts)
{
	// static int	check;

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
		// if (check == 0)
		// 	check = draw_enemy(map_data, i, j);
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
