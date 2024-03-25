/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bperez-a <bperez-a@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 07:51:08 by bperez-a          #+#    #+#             */
/*   Updated: 2024/03/21 16:41:36 by bperez-a         ###   ########.fr       */
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
	mlx_delete_image(map_data->mlx, map_data->wall_image);
	mlx_delete_image(map_data->mlx, map_data->player_image);
	mlx_delete_image(map_data->mlx, map_data->exit_image);
	mlx_delete_image(map_data->mlx, map_data->floor_image);
	mlx_delete_image(map_data->mlx, map_data->collectible_image);
	mlx_terminate(map_data->mlx);
	free(map_data);
	exit(EXIT_SUCCESS);
}
