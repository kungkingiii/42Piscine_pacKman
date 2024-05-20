/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:39:23 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/20 21:55:06 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"
// #define	IM1_SX		42
// #define	IM1_SY		42

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;


// // void detroy_all(t_data *data)
// // {
// //     if (data->im1)
// // 	{
// // 			mlx_destroy_image(data->mlx, data->im1);
// // 	}
// // 	if (data->img2)
// // 	{
// // 			mlx_destroy_image(data->mlx, data->img2);
// // 	}
// // 	if (data->window)
// // 	{
// // 		mlx_destroy_window(data->mlx, data->window);
// // 	}
	
// // 	if (data->mlx)
// // 	{
// // 		mlx_destroy_display(data->mlx);
// // 		free(data->mlx);
// // 	}
// // 	exit(1);
// // }

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// // int	key_hook(int keycode, t_data *data)
// // {
// // 	if(keycode == 's')
// // 	{
// // 		detroy_all(data);
		
// // 	}
// // }

// int	main()
// {

// 	void	*window;
// 	void	*mlx;
// 	t_data	img;
// 	int a;
// 	int b;
// 	void	*im1;
// 	void	*im2;

// 	mlx = mlx_init();
// 	window = mlx_new_window(mlx, 800, 600, "so_long");
// 	// img.img = mlx_new_image(mlx, 800, 600);

// 	/*
// 	** After creating an image, we can call `mlx_get_data_addr`, we pass
// 	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
// 	** then be set accordingly for the *current* data address.
// 	*/
// 	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 	// 							&img.endian);

// 	// my_mlx_pixel_put(&img, 50, 50, 0xFF70AB);
// 	// mlx_put_image_to_window(mlx, window, img.img, 50, 80);
// 	im2 = mlx_xpm_file_to_image(mlx,"open.xpm",&a,&b);
// 	mlx_put_image_to_window(mlx,window,im2,500,200);
// 	im1 = mlx_xpm_file_to_image(mlx,"open24.xpm",&a,&b);
// 	mlx_put_image_to_window(mlx,window,im1,100,200);
// 	// mlx_key_hook(window, key_hook, &img);
// 	mlx_loop(mlx);
 
//   // mlx_loop(mlx);
//    if (!(mlx = mlx_init()))
//     {
//       printf(" !! KO !!\n");
//       exit(1);
//     }
//    if (im1)
// 	{
// 			mlx_destroy_image(mlx, im1);
// 	}
// 	if (im2)
// 	{
// 			mlx_destroy_image(mlx, im2);
// 	}

// 	if (window)
// 	{
// 		mlx_destroy_window(mlx, window);
// 	}
	
// 	if (mlx)
// 	{
// 		mlx_destroy_display(mlx);
// 		free(mlx);
// 	}
// }

// #include "./so_long.h"
// #define    IM1_SX        42
// #define    IM1_SY        42

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
	int a;
	int b;
	void	*im1;
	void	*img2;
	// char *str = argv[0];
	t_data data;

	
	// if (argc != 2)
	// {
	// 	ft_printf("require 2 argument (Usage: ./solong /path-to-map)%s\n", str);
	// 	return (1);
	// }
	data.mlx = mlx_init();
	data.window = mlx_new_window(data.mlx, 640, 640, "so_long");

	data.img2 = mlx_xpm_file_to_image(data.mlx,"open.xpm",&a,&b);
	mlx_put_image_to_window(data.mlx,data.window,data.img2,1,1);
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