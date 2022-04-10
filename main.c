/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:13:05 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/10 19:52:07 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_exit(char *str)
{
	if (!str)
		exit(1);
	return (1);
}

int	main(int argc, char **argv)
{
	t_struct	*game;

	if (argc != 2)
		exit(EXIT_FAILURE);
	game = malloc(sizeof(t_struct));
	ft_map_check(argv[1], game);
	game->mlx = mlx_init();
	ft_distribution(game);
	game->win = mlx_new_window(game->mlx, game->map_width * 64,
			game->map_height * 64, "heykamikaze");
	ft_place_pic(game);
	mlx_hook(game->win, 17, 0, ft_exit, NULL);
	mlx_hook(game->win, 2, 1L << 0, ft_check_key, game);
	mlx_loop(game->mlx);
}
