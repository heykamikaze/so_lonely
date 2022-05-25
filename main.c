/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:13:05 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/26 00:39:31 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(t_struct *game)
{
	if (game->line)
		free(game->line);
	if (game->map)
		ft_free(game->map);
	exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*game;

	if (argc != 2)
		exit(EXIT_FAILURE);
	game = malloc(sizeof(t_struct));
	if (!game)
		exit(EXIT_FAILURE);
	game->b_flag = 0;
	game->d_flag = 0;
	ft_map_check(argv[1], game);
	game->mlx = mlx_init();
	ft_distribution(game);
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "heykamikaze");
	ft_place_pic(game);
	mlx_hook(game->win, 17, 0, ft_exit, game);
	mlx_hook(game->win, 2, 1L << 0, ft_check_key, game);
	mlx_loop_hook(game->mlx, ft_render_enemy, game);
	mlx_loop(game->mlx);
}
