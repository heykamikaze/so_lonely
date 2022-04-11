/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:28:58 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/11 19:36:53 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_distribution(t_struct *game)
{
	game->wall.path = "./pics/wall.xpm";
	game->floor.path = "./pics/floor.xpm";
	game->player.path = "./pics/player.xpm";
	game->exit.path = "./pics/exit.xpm";
	game->col.path = "./pics/col.xpm";
	game->b_enemy.path = "./pics/b_enemy.xpm";
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
	game->b_enemy.img = mlx_xpm_file_to_image(game->mlx, \
	game->b_enemy.path, &game->b_enemy.width, &game->b_enemy.height);
	game->steps = 0;
}

void	ft_place_pic(t_struct *game)
{
	int	y;
	int	x;

	y = 0;
	while (game->map[y])
	{
		x = 0;
		while (game->map[y][x])
		{
			ft_draw(game, x, y);
			x++;
		}
		y++;
	}
}

void	ft_draw(t_struct *game, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, \
			game->floor.img, x * 64, y * 64);
	if (game->map[y][x] == '1')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->wall.img, x * 64, y * 64);
	if (game->map[y][x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->player.img, x * 64, y * 64);
	if (game->map[y][x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->exit.img, x * 64, y * 64);
	if (game->map[y][x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->col.img, x * 64, y * 64);
	if (game->map[y][x] == 'B')
		mlx_put_image_to_window(game->mlx, game->win, \
			game->b_enemy.img, x * 64, y * 64);
}

int	ft_check_key(int key, t_struct *game)
{
	if (key == D)
		ft_move(game, 1, 0);
	if (key == S)
		ft_move(game, 0, 1);
	if (key == A)
		ft_move(game, -1, 0);
	if (key == W)
		ft_move(game, 0, -1);
	if (key == ESC)
		exit (1);
	return (1);
}

void	ft_counter(t_struct *game)
{
	char	*steps_str;

	if (game->b_flag == 1)
	{
		steps_str = ft_itoa(game->steps);
		mlx_string_put(game->mlx, game->win, 65, 65, 0x00FF0000, steps_str);
		free(steps_str);
	}
	else
	{
		ft_putnbr_fd(game->steps, 1);
		ft_putchar_fd('\n', 1);
	}
}
