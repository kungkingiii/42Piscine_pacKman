/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 14:05:26 by bperez-a          #+#    #+#             */
/*   Updated: 2024/04/18 13:34:17 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../solong.h"

void	ft_hook(void *param)
{
	t_map	*map_data;

	map_data = (t_map *)param;
	if (mlx_is_key_down(map_data->mlx, MLX_KEY_ESCAPE))
		exit_routine(map_data);
	else if (mlx_is_key_down(map_data->mlx, MLX_KEY_W))
		handle_move(0, -1, map_data);
	else if (mlx_is_key_down(map_data->mlx, MLX_KEY_S))
		handle_move(0, 1, map_data);
	else if (mlx_is_key_down(map_data->mlx, MLX_KEY_A))
		handle_move(-1, 0, map_data);
	else if (mlx_is_key_down(map_data->mlx, MLX_KEY_D))
		handle_move(1, 0, map_data);
}

int32_t	main(int argc, char **argv)
{
	t_map	*map_data;

	if (argc != 2)
	{
		ft_printf("Usage: ./solong /path/to/map\n");
		return (EXIT_FAILURE);
	}
	map_data = handle_input(argv[1]);
	if (map_data == NULL)
	{
		ft_printf("Error: creating map\n");
		return (EXIT_FAILURE);
	}
	mlx_set_setting(MLX_STRETCH_IMAGE, true);
	map_data->mlx = mlx_init(TILESIZE * map_data->cols,
			TILESIZE * map_data->rows, "so_long", true);
	init_textures_and_images(map_data);
	draw_map(map_data);
	mlx_loop_hook(map_data->mlx, ft_hook, map_data);
	mlx_loop(map_data->mlx);
}
