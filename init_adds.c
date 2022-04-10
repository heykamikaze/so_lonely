/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_adds.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 00:43:40 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/11 01:35:39 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    ft_loose(t_struct *game)
{
    mlx_destroy_window(game->mlx, game->win);
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "heykamikaze");
	mlx_string_put(game->mlx, game->win, 10 * 16 - 16,
		10 * 16 - 16, 0x0066FF33, "YOU DIE!");
	mlx_hook(game->win, 17, 0, ft_exit, NULL);
	// mlx_key_hook(game->win, ft_end, game);
}

int	ft_end(int keycode, t_struct *game)
{
	(void)game;
	if (keycode == 53)
		exit(0);
	return (0);
}