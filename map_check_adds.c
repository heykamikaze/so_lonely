/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_adds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:23:43 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/12 19:39:13 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_width_check(t_struct *game)
{
	size_t	check;
	int		i;

	i = 0;
	check = ft_strlen(game->map[0]);
	while (game->map[i])
	{
		if (check != ft_strlen(game->map[i++]))
			ft_error();
	}
	return (check);
}

int	ft_map_check(char *map, t_struct *game)
{
	int		i;
	int		fd;

	game->col_count = 0;
	game->line = NULL;
	i = -1;
	fd = open(map, O_RDONLY);
	ft_check_name(map);
	game->line = ft_collect_map(fd, game->line);
	ft_height_check(game->line, game);
	game->map_width = ft_width_check(game);
	ft_check_player(game);
	ft_check_e(game);
	ft_check_walls(game);
	while (game->map[++i])
	{
		if (ft_line_ok(game->map[i]) == 1)
			ft_error();
	}
	return (0);
}

void	ft_move(t_struct *game, int d_x, int d_y)
{	
	if (game->map[game->p_y + d_y][game->p_x + d_x] != '1')
	{
		if (game->map[game->p_y + d_y][game->p_x + d_x] == 'E'
		&& game->col_count == 0)
			ft_exit(game);
		if (game->map[game->p_y + d_y][game->p_x + d_x] == 'B')
			ft_exit(game);
		else if (game->map[game->p_y + d_y][game->p_x + d_x] == 'E')
			return ;
		if (game->map[game->p_y + d_y][game->p_x + d_x] == 'C')
			game->col_count--;
		game->map[game->p_y][game->p_x] = '0';
		game->map[game->p_y + d_y][game->p_x + d_x] = 'P';
		game->p_y = game->p_y + d_y;
		game->p_x = game->p_x + d_x;
		game->steps++;
		ft_place_pic(game);
		ft_counter(game);
	}
}

void	ft_check_e(t_struct *game)
{
	int	i;
	int	j;

	game->e_count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'E')
				game->e_count++;
			if (game->map[i][j] == 'B')
				game->b_flag = 1;
			j++;
		}
		i++;
	}
	if (game->e_count != 1)
		ft_error();
}

void	ft_check_walls(t_struct *game)
{
	int	i;
	int	j;

	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if ((i == 0 || i == game->map_height - 1) && game->map[i][j] != '1')
				ft_error();
			j++;
		}
		i++;
	}
}
