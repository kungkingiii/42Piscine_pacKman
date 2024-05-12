/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: packmanich <packmanich@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/24 20:39:23 by packmanich        #+#    #+#             */
/*   Updated: 2024/05/12 20:38:09 by packmanich       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minilibx-linux/mlx.h"
#include "../minilibx-linux/mlx_int.h"
#define	IM1_SX		42
#define	IM1_SY		42

typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_data;


void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main()
{

	void	*window;
	void	*mlx;
	t_data	img;
	int a;
	int b;
	void	*im1;
	void	*im2;

	mlx = mlx_init();
	window = mlx_new_window(mlx, 800, 600, "so_long");
	// img.img = mlx_new_image(mlx, 800, 600);

	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	// img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
	// 							&img.endian);

	// my_mlx_pixel_put(&img, 50, 50, 0xFF70AB);
	// mlx_put_image_to_window(mlx, window, img.img, 50, 80);
	im2 = mlx_xpm_file_to_image(mlx,"open.xpm",&a,&b);
	mlx_put_image_to_window(mlx,window,im2,500,200);
	im1 = mlx_xpm_file_to_image(mlx,"open24.xpm",&a,&b);
	mlx_put_image_to_window(mlx,window,im1,100,200);
	mlx_loop(mlx);
 
  // mlx_loop(mlx);
  //  if (!(mlx = mlx_init()))
  //   {
  //     printf(" !! KO !!\n");
  //     exit(1);
  //   }
	// if (window)
	// {
	// 	mlx_destroy_window(mlx, window);
	// }
	
	// if (mlx)
	// {
	// 	mlx_destroy_display(mlx);
	// 	free(mlx);
	// }
}