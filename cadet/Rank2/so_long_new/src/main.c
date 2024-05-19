/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:39:23 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/20 00:52:53 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	key_hook(int keycode, t_data *data)
{
	if(keycode == 's')
	{
		detroy_all(data);
		
	}

	return (0);
}


int	main()
{
	// int a;
	// int b;
	// char *str = argv[0];
	t_data data;

	
	// if (argc != 2)
	// {
	// 	ft_printf("require 2 argument (Usage: ./solong /path-to-map)%s\n", str);
	// 	return (1);
	// }
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 640, 640, "so_long");

	// data.img2 = mlx_xpm_file_to_image(data.mlx,"../textures/player.xpm",&a,&b);
	// mlx_put_image_to_window(data.mlx,data.window,data.img2,1,1);
	// data.img1 = mlx_xpm_file_to_image(data.mlx,"../textures/enemy.xpm",&a,&b);
	// mlx_put_image_to_window(data.mlx,data.window,data.img1,64,64);
	mlx_key_hook(data.window, key_hook, &data);
	mlx_loop(data.mlx);
 
  // mlx_loop(mlx);
  //  if (!(mlx = mlx_init()))
  //   {
  //     printf(" !! KO !!\n");
  //     exit(1);
  //   }
	
	
}