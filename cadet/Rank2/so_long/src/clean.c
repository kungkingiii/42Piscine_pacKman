/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:51:08 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/13 11:37:33 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	exit_routine(t_map *map_data)
{
	int	map_len;

	map_len = ft_c_arr_len(map_data->map);
	while (map_len--)
		free(map_data->map[map_len]);
	free(map_data->map);
	free(map_data->c_x);
	free(map_data->c_y);
	mlx_delete_image(map_data->mlx, map_data->wall_img);
	mlx_delete_image(map_data->mlx, map_data->player_img);
	mlx_delete_image(map_data->mlx, map_data->wall_img);
	mlx_delete_image(map_data->mlx, map_data->floor_img);
	mlx_delete_image(map_data->mlx, map_data->collectible_img);
	mlx_terminate(map_data->mlx);
	free(map_data);
	exit(EXIT_SUCCESS);
}
