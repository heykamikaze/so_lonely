#ifndef SO_LONG_H
# define SO_LONG_H


# include "mlx/mlx.h"
# include <fcntl.h>
# include <stdlib.h>
# include <limits.h>
# include <unistd.h>
# include <stdio.h>
# include "get_next_line.h"
# define MAX "./pics/threat.xpm"

typedef struct s_img {
	void	*img;
	int		x;
	int		y;
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
    t_img	wall;
	t_img	floor;
}		t_struct;

int main(int argc, char **argv);
char	*get_next_line(int fd);
int	ft_height_check(char *map);
void	ft_putstr_fd(char *s, int fd);
void	ft_error(void);
int	ft_strlen(char *s);
int	ft_line_ok(char *line, t_struct *game);
void	create_box(int type, int *counter, int *item);
int	*get_map_line(char *line, t_struct *game, int c);
int	ft_map_check(char *map, t_struct *game);
void	distribution(t_struct *game);

#endif
