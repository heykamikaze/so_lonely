/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/27 15:49:01 by nbenjami          #+#    #+#             */
/*   Updated: 2022/05/27 17:00:42 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define BUFFER_SIZE 1
# define D 2
# define A 0
# define W 13
# define S 1
# define ESC 53

typedef struct s_img {
	void	*img;
	char	*path;
	int		width;
	int		height;
}	t_img;

typedef struct s_struct{
	char	**map;
	void	*mlx;
	void	*win;
	int		**map_i;
	int		map_height;
	int		map_width;
	int		col_count;
	int		e_count;
	int		p_y;
	int		p_x;
	int		by;
	int		bx;
	int		steps;
	int		b_flag;
	int		d_flag;
	char	*line;
	t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	col;
	t_img	b_enemy;
}		t_struct;

int		main(int argc, char **argv);
int		ft_height_check(char *map, t_struct *game);
int		ft_line_ok(char *line);
int		ft_map_check(char *map, t_struct *game);
void	ft_distribution(t_struct *game);
void	ft_check_name(char *map);
char	*ft_collect_map(int fd, char *line);
int		ft_width_check(t_struct *game);
int		ft_exit(t_struct *game);
void	ft_place_pic(t_struct *game);
int		ft_check_key(int key, t_struct *game);
void	ft_check_player(t_struct *game);
void	ft_move(t_struct *game, int d_x, int d_y);
void	ft_check_key1(int key, t_struct *game);
void	ft_draw(t_struct *game, int x, int y);
void	ft_check_e(t_struct *game);
void	ft_check_walls(t_struct *game);
void	ft_keys(int key, t_struct *game);
void	ft_counter(t_struct *game);
int		ft_render_enemy(t_struct *game);
void	ft_draw_enemy1(t_struct *game, char *sprite, int sign);
void	ft_draw_enemy(t_struct *game);
void	ft_rights_check(t_struct *game);
void	ft_screen(t_struct *game);

#endif