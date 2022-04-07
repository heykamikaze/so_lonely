#include "so_long.h"

void	distribution(t_struct *game)
{
	game->wall.path = "./pics/wall.xpm";
	game->floor.path = "./pics/floor.xpm";
	game->player.path = "./pics/player.xpm";
	game->exit.path = "./pics/exit.xpm";
	game->wall.img = mlx_xpm_file_to_image(game->mlx, \
	game->wall.path, &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, \
	game->floor.path, &game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	game->player.path, &game->player.width, &game->player.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, \
	game->exit.path, &game->exit.width, &game->exit.height);
}

void place_pic(t_struct *game)
{
	int y;
	int x;
	
	y = 0;
	while (game->map[y]) 
	{
		x = 0;
		while (game->map[y][x])
		{
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x * 64, y * 64);
			if (game->map[y][x] == '0')
				mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.img, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}