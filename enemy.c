/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:14:01 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/26 20:54:38 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

// void	get_pos(t_struct *game, char c, int y)
// {
// 	int	x;

// 	while ((game->map)[y])
// 	{
// 		x = 0;
// 		while (game->map[y][x] && game->map[y][x] != c)
// 			x++;
// 		if (game->map[y][x])
// 			break ;
// 		y++;
// 	}
// 	if (game->map[y] && game->map[y][x] == c)
// 	{
// 		game->bx = x;
// 		game->by = y;
// 	}
// }

void	draw_enemy1(t_struct *game, char *sprite, int sign)
{
	int	y;
	int x;

	y = 0;
	x = 0;
	while ((game->map)[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != 'B')
			x++;
		game->b_enemy.path = sprite;
		game->b_enemy.img = mlx_xpm_file_to_image(game->mlx, \
		game->b_enemy.path, &game->b_enemy.width, &game->b_enemy.height);
		if ((game->map)[y] && game->map[y][x + sign] != '1' \
		&& game->map[y][x + sign] != 'E' && game->map[y][x + sign] != 'B')
		{
			if (game->map[y][x + sign] == 'P')
				ft_exit(game);
			else
				game->map[y][x] = '0';
			game->map[y][x + sign] = 'B';
		}
		y++;
	}
}

void	draw_enemy(t_struct *game)
{
	static int	acc = -60;
	char		*steps;

	steps = ft_itoa(game->steps);
	if (acc == -90)
		draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == -60)
		draw_enemy1(game, "./pics/player.xpm", -1);
	if (acc == -30)
		draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == 0)
		draw_enemy1(game, "./pics/player.xpm", 1);
	if (acc == 30)
		draw_enemy1(game, "./pics/b_enemy.xpm", 1);
	if (acc == 60)
		draw_enemy1(game, "./pics/player.xpm", 1);
	acc++;
	if (acc > 90)
		acc = -90;
	ft_place_pic(game);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0066FF33, steps);
	free(steps);
}

int ft_render_enemy(t_struct *game)
{
    char		*steps;

	if (game->b_flag == 1)
		draw_enemy(game);
	else
	{
		steps = ft_itoa(game->steps);
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, steps);
		free(steps);
	}
	return (1);
}