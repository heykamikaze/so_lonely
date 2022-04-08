#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "libft/libft.h"
# define MAX "./pics/threat.xpm"
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
	int		p_y;
	int		p_x;
	int	steps;
    t_img	wall;
	t_img	floor;
	t_img	player;
	t_img	exit;
	t_img	col;
}		t_struct;

int main(int argc, char **argv);
char	*get_next_line(int fd);
int	ft_height_check(char *map, t_struct *game);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(void);
int	ft_line_ok(char *line);
void	create_box(int type, int *counter, int *item);
int	*get_map_line(char *line, t_struct *game, int c);
int	ft_map_check(char *map, t_struct *game);
void	distribution(t_struct *game);
void	ft_check_name(char *map);
char *ft_collect_map(int fd, char *line);
int	ft_width_check(t_struct *game);
int	ft_exit(char *str);
void place_pic(t_struct *game);
int	check_key(int key, t_struct *game);
void	check_player(t_struct *game);
void move(t_struct *game, int d_x, int d_y);

#endif
