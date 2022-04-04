#include "so_long.h"

void	distribution(t_struct *game)
{
	game->wall.path = "./pics/wall.xpm";
	game->floor.path = "./pics/floor.xpm";
	game->wall.img = mlx_xpm_file_to_image(game->mlx, \
	game->wall.path, &game->wall.width, &game->wall.height);
	game->floor.img = mlx_xpm_file_to_image(game->mlx, \
	game->floor.path, &game->floor.width, &game->floor.height);
	//no positions
}