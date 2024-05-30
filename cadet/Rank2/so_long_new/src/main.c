/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chongsen <chongsen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:39:23 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/30 14:14:04 by chongsen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

int	key_hook(int key, t_data *data)
{
	if (key == ESC || key == KEY_X)
		quit_game(data, 0);
	else if (key == W || key == UP)
		handle_move(data, 0, -1);
	else if (key == A || key == LEFT)
		handle_move(data, -1, 0);
	else if (key == S || key == DOWN)
		handle_move(data, 0, 1);
	else if (key == D || key == RIGHT)
		handle_move(data, 1, 0);
	return (EXIT_SUCCESS);
}

void	run_game(t_data *data)
{
	init_image(data);
	draw_map(data);
	mlx_hook(data->window, 2, (1L << 0), key_hook, data);
	mlx_hook(data->window, 17, (1L << 17), quit_game, data);
}

int	main(int argc, char **argv)
{
	t_data	*data;

	if (argc != 2)
	{
		ft_printf("require 2 argument ./solong /path-to-map\n");
		return (0);
	}
	data = handle_input(argv[1]);
	if (data == NULL)
	{
		ft_printf("Error: can't create map\n");
		return (0);
	}
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx,
			WINSIZE * data->cols, WINSIZE * data->rows, "so_long");
	if (data == NULL)
	{
		ft_printf("Error: can't open something wrong\n");
		quit_game(data, 0);
		return (0);
	}
	run_game(data);
	mlx_loop(data->mlx);
}
