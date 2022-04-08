#include "so_long.h"

void	distribution(t_struct *game)
{
	game->wall.path = "./pics/wall.xpm";
	game->floor.path = "./pics/floor.xpm";
	game->player.path = "./pics/player.xpm";
	game->exit.path = "./pics/exit.xpm";
	game->col.path = "./pics/col.xpm";
	game->wall.img = mlx_xpm_file_to_image(game->mlx, \
	game->wall.path, &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, \
	game->floor.path, &game->floor.width, &game->floor.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, \
	game->player.path, &game->player.width, &game->player.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, \
	game->exit.path, &game->exit.width, &game->exit.height);
	game->col.img = mlx_xpm_file_to_image(game->mlx, \
	game->col.path, &game->col.width, &game->col.height);
	game->steps = 0;
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
			mlx_put_image_to_window(game->mlx, game->win, game->floor.img, x * 64, y * 64);
			if (game->map[y][x] == '1')
				mlx_put_image_to_window(game->mlx, game->win, game->wall.img, x * 64, y * 64);
			if (game->map[y][x] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.img, x * 64, y * 64);
			if (game->map[y][x] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->exit.img, x * 64, y * 64);
			if (game->map[y][x] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, game->col.img, x * 64, y * 64);
			x++;
		}
		y++;
	}
}

int	check_key(int key, t_struct *game)
{
	char *steps_str;
	if (key == D)
		{
			move(game, 1, 0);
			game->steps++;
		}
	if (key == S)
		{
			move(game, 0, 1);
			game->steps++;
		}
	if (key == A)
		{
			move(game, -1, 0);
			game->steps++;
		}
	if (key == W)
		{
			move(game, 0, -1);
			game->steps++;
		}
	if (key == ESC)
		exit(1);
	steps_str = ft_itoa(game->steps);
	mlx_string_put(game->mlx, game->win, 65, 65, 0x00FF0000, steps_str);
	free(steps_str);
	return(1);
}

void move(t_struct *game, int d_x, int d_y)
{
	// char *steps_str;
	
	if (game->map[game->p_y + d_y][game->p_x + d_x] != '1')
	{
		if (game->map[game->p_y + d_y][game->p_x + d_x] == 'E' && game->col_count == 0)
			exit(1);
		else if (game->map[game->p_y + d_y][game->p_x + d_x] == 'E')
			return ;
		if (game->map[game->p_y + d_y][game->p_x + d_x] == 'C')
			game->col_count--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y + d_y][game->p_x + d_x] = 'P';
		game->p_y = game->p_y + d_y;
		game->p_x = game->p_x + d_x;
		place_pic(game);
		// steps_str = ft_itoa(game->steps);
		// mlx_string_put(game->mlx, game->win, 10, 10, 0x0000FF00, steps_str);
		// free(steps_str);
	}
}