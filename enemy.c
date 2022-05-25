/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/25 23:14:01 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/26 00:41:19 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_pos(t_struct *game, char c)
{
	int	x;
	int	y;

	y = 0;
	while ((game->map)[y])
	{
		x = 0;
		while (game->map[y][x] && game->map[y][x] != c)
			x++;
		if (game->map[y][x])
			break ;
		y++;
	}
	game->p_x = x;
	game->p_y = y;
}

void	draw_enemy1(t_struct *game, char *sprite, int sign)
{
	get_pos(game, 'B');
	game->b_enemy.path = sprite;
	game->b_enemy.img = mlx_xpm_file_to_image(game->mlx, \
	game->b_enemy.path, &game->b_enemy.width, &game->b_enemy.height);
	if (game->map[game->p_y][game->p_x + sign] != '1' \
	&& game->map[game->p_y][game->p_x + sign] != 'E')
	{
		if (game->map[game->p_y][game->p_x + sign] == 'P')
			game->d_flag = 1;
		else
			game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y][game->p_x + sign] = 'B';
	}
}

void	draw_enemy(t_struct *game)
{
	static int	acc = -60;
	char		*steps;

	steps = ft_itoa(game->steps);
	if (acc == -90)
		draw_enemy1(game, "./pics/b_enemy.xpm", 1);
	if (acc == -60)
		draw_enemy1(game, "./pics/b_enemy.xpm", 1);
	if (acc == -30)
		draw_enemy1(game, "./pics/b_enemy.xpm", 1);
	if (acc == 0)
		draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == 30)
		draw_enemy1(game, "./pics/b_enemy.xpm", -1);
	if (acc == 60)
		draw_enemy1(game, "./pics/b_enemy.xpm", -1);
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