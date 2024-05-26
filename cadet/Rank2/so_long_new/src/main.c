/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:39:23 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/26 15:28:41 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

// int	key_hook(int keycode, t_data *data)
// {
// 	if(keycode == ESC)
// 	{
// 		quit_game(data, 1);
// 	}
// 	return (0);
// }

int	key_hook(int key, t_data *data)
{
	if (key == ESC || key == KEY_X)
		quit_game(data, 0);
	// else if (key == W || key == UP)
	// 	player_pos(game, false, -1);
	// else if (key == A || key == LEFT)
	// 	player_pos(game, true, -1);
	// else if (key == S || key == DOWN)
	// 	player_pos(game, false, 1);
	// else if (key == D || key == RIGHT)
	// 	player_pos(game, true, 1);
	return (EXIT_SUCCESS);
}


int	main(int argc, char **argv)
{
	t_data *data;

	
	if (argc != 2)
	{
		ft_printf("require 2 argument (Usage: ./solong /path-to-map)%s\n",argv[1]);
		return (0);
	}

	
	data = handle_input(argv[1]);
	if (data == NULL)
	{
		ft_printf("Error: can't create map\n");
		return (0);
	}
	data->mlx = mlx_init();
	data->window = mlx_new_window(data->mlx, WINSIZE * data->cols, WINSIZE * data->rows, "so_long");
	if (data == NULL)
	{
		ft_printf("Error: can't open something wrong\n");
		detroy_all(data);
		return (0);
	}
	init_image(data);
	draw_map(data);
	// data->player = mlx_xpm_file_to_image(data->mlx,"../textures/player.xpm",&a,&b);
	// mlx_put_image_to_window(data->mlx,data->window,data->player,10,10);
	// data->enemy = mlx_xpm_file_to_image(data->mlx,"../textures/enemy.xpm",&a,&b);
	// mlx_put_image_to_window(data->mlx,data->window,data->enemy,64,64);
	// mlx_key_hook(data->window, key_hook, &data);
	mlx_hook(data->window, 2, (1L << 0), key_hook, data);
	mlx_hook(data->window, 17, (1L << 17), quit_game, data);
	mlx_loop(data->mlx);
 
  // mlx_loop(mlx);
  //  if (!(mlx = mlx_init()))
  //   {
  //     printf(" !! KO !!\n");
  //     exit(1);
  //   }
	
	
}