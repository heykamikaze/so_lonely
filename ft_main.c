#include "so_long.h"


// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 800, 540, "void");
// 	mlx_loop(mlx);
// }
// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

// void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
// {
// 	char	*dst;

// 	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
// 	*(unsigned int*)dst = color;
// }

// int	main(void)
// {
// 	void	*mlx;
// 	void	*mlx_win;
// 	t_data	img;

// 	mlx = mlx_init();
// 	mlx_win = mlx_new_window(mlx, 540, 540, "Hello world!");
// 	img.img = mlx_new_image(mlx, 540, 540);
// 	img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
// 								&img.endian);
// 	my_mlx_pixel_put(&img, 12, 20, 0x00FF0000);
//     // mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
//     my_mlx_pixel_put(&img, 5, 5, 0x0000FF00);
// 	mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
// 	mlx_loop(mlx);
// }

int	ft_exit(char *str)
{
	if (!str)
		exit(1);
	return (1);
}

int main(int argc, char **argv)
{
    // t_struct	*game;

	// if (argc != 2)
	// 	ft_putstr_fd("Egor", 2);
    //     exit(EXIT_FAILURE);
	// game = malloc(sizeof(t_struct));
    // if (ft_map_check(argv[1], game))
	// 	return (1);
	// game->win = mlx_new_window(game->mlx, game->map_width * 50,
	// 		game->map_height * 50, "heykamikaze");
       
	// void	*mlx_win;
	t_struct	*game;

	// ft_putstr_fd("Egvor", 2);
	if (argc != 2)
	{
		// ft_putstr_fd("Egor", 2);
        exit(EXIT_FAILURE);
	}
	game = malloc(sizeof(t_struct));	
	// ft_putstr_fd("Egr", 2);
    if (ft_map_check(argv[1], game))
		return (1);
	// ft_putstr_fd("lala", 2);
	game->mlx = mlx_init();
	distribution(game);
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "heykamikaze");
	place_pic(game);
	mlx_hook(game->win, 17, 0, ft_exit, NULL);
	mlx_loop(game->mlx);
}
