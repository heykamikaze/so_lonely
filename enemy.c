/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:14:01 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/27 16:51:33 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_draw_enemy1(t_struct *game, char *sprite, int sign)
{
	int	y;
	int	x;

	y = 0;
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

void	ft_draw_enemy(t_struct *game)
{
	static int	acc = -60;
	char		*steps;

	steps = ft_itoa(game->steps);
	if (acc == -90)
		ft_draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == -60)
		ft_draw_enemy1(game, "./pics/player.xpm", -1);
	if (acc == -30)
		ft_draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == 0)
		ft_draw_enemy1(game, "./pics/player.xpm", 1);
	if (acc == 30)
		ft_draw_enemy1(game, "./pics/b_enemy.xpm", 1);
	if (acc == 60)
		ft_draw_enemy1(game, "./pics/player.xpm", 1);
	acc++;
	if (acc > 90)
		acc = -90;
	ft_place_pic(game);
	mlx_string_put(game->mlx, game->win, 0, 0, 0x0066FF33, steps);
	free(steps);
}

int	ft_render_enemy(t_struct *game)
{
	char	*steps;

	if (game->b_flag == 1)
		ft_draw_enemy(game);
	else
	{
		steps = ft_itoa(game->steps);
		mlx_clear_window(game->mlx, game->win);
		mlx_string_put(game->mlx, game->win, 0, 0, 0x00FF0000, steps);
		free(steps);
	}
	ft_counter(game);
	return (1);
}

void	ft_rights_check(t_struct *game)
{
	if (!mlx_xpm_file_to_image(game->mlx, \
	game->wall.path, &game->wall.width, &game->wall.height)
		|| !mlx_xpm_file_to_image(game->mlx, \
	game->floor.path, &game->floor.width, &game->floor.height)
		|| !mlx_xpm_file_to_image(game->mlx, \
	game->player.path, &game->player.width, &game->player.height)
		|| !mlx_xpm_file_to_image(game->mlx, \
	game->exit.path, &game->exit.width, &game->exit.height)
		|| !mlx_xpm_file_to_image(game->mlx, \
	game->b_enemy.path, &game->b_enemy.width, &game->b_enemy.height))
		ft_error();
}
