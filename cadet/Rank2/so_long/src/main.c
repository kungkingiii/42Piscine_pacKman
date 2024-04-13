#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
// #include "../MLX42/include/MLX42/MLX42.h"
#include "../solong.h"

#define WIDTH 512
#define HEIGHT 512


// typedef struct s_map
// {
// 	char		**map;
// 	int			rows;
// 	int			cols;
// 	int			collectibles;
// 	int			collected;
// 	int			*c_x;
// 	int			*c_y;
// 	int			moves;
// 	mlx_image_t	*wall_img;
// 	mlx_image_t	*player_img;
// 	mlx_image_t	*exit_img;
// 	mlx_image_t	*collectible_img;
// 	mlx_image_t	*floor_img;
// 	mlx_t		*mlx;

// }				t_map;
// static mlx_image_t* image;

// -----------------------------------------------------------------------------

// int32_t ft_pixel(int32_t r, int32_t g, int32_t b, int32_t a)
// {
//     return (r << 24 | g << 16 | b << 8 | a);
// }

// void ft_randomize(void* param)
// {
// 	(void)param;
// 	for (uint32_t i = 0; i < image->width; ++i)
// 	{
// 		for (uint32_t y = 0; y < image->height; ++y)
// 		{
// 			uint32_t color = ft_pixel(
// 				rand() % 0xFF, // R
// 				rand() % 0xFF, // G
// 				rand() % 0xFF, // B
// 				rand() % 0xFF  // A
// 			);
// 			mlx_put_pixel(image, i, y, color);
// 		}
// 	}
// }

void ft_hook(void* param)
{
	t_map	*map_data;

	if (mlx_is_key_down(map_data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(map_data->mlx);
	if (mlx_is_key_down(map_data->mlx, MLX_KEY_UP))
		// image->instances[0].y -= 5;
	if (mlx_is_key_down(map_data->mlx, MLX_KEY_DOWN))
		// image->instances[0].y += 5;
	if (mlx_is_key_down(map_data->mlx, MLX_KEY_LEFT))
		// image->instances[0].x -= 5;
	if (mlx_is_key_down(map_data->mlx, MLX_KEY_RIGHT))
		ft_printf("right");
		// image->instances[0].x += 5;
}

// -----------------------------------------------------------------------------

// int32_t main(void)
// {
// 	// mlx_t* mlx;
// 	t_map	*the_map;

// 	// Gotta error check this stuff
// 	if (!(mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true)))
// 	{
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (!(image = mlx_new_image(mlx, 15, 128)))
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
// 	if (mlx_image_to_window(mlx, image, 0, 0) == -1)
// 	{
// 		mlx_close_window(mlx);
// 		puts(mlx_strerror(mlx_errno));
// 		return(EXIT_FAILURE);
// 	}
	
// 	mlx_loop_hook(mlx, ft_randomize, mlx);
// 	mlx_loop_hook(mlx, ft_hook, mlx);

// 	mlx_loop(mlx);
// 	mlx_terminate(mlx);
// 	return (EXIT_SUCCESS);
// }


int32_t main(int argc, char **argv)
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
	// map_data->mlx = mlx_init(WIDTH, HEIGHT, "MLX42", true);
	map_data->mlx = mlx_init(TILESIZE * map_data->cols,
			TILESIZE * map_data->rows, "solong", true);
	init_images(map_data);
	draw_map(map_data);
	mlx_loop_hook(map_data->mlx, ft_hook, map_data);
	mlx_loop(map_data->mlx);
	ft_printf("mapppp\n");

	// return (EXIT_SUCCESS);
}