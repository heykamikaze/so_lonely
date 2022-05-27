/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:13:05 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/27 17:09:34 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_screen(t_struct *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	if (!game->mlx || !game->win)
		ft_error();
	if (!game->win)
		ft_error();
	// mlx_get_screen_size(game->mlx, &x, &y);
	if ((x / 64) > 40 || (y / 64) > 21)
		ft_error();
}

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
	// ft_screen(game);
	mlx_hook(game->win, 17, 0, ft_exit, game);
	mlx_hook(game->win, 2, 1L << 0, ft_check_key, game);
	mlx_loop_hook(game->mlx, ft_render_enemy, game);
	mlx_loop(game->mlx);
}
