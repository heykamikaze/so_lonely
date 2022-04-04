#include "so_long.h"


int	ft_height_check(char *map)
{
	// int		fd;
	int		height;
	char	*line;

	height = 0;
	while (open(map, O_RDONLY) == 1)
	{
		line = get_next_line(1);
		if (!line)
			break ;
		height++;
		free(line);
	}
	// close(fd);
	return (height);
}

int	ft_line_ok(char *line, t_struct *game)
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	game->map_width = len;
	i = -1;
	while (++i < len)
	{
		if (i == 0 || len - i == 1 || i == game->map_height - 1)
			if (line[i] != 49)
				return (1);
		if (line[i] != 48 && line[i] != 49 && line[i] != 67
			&& line[i] != 69 && line[i] != 80)
			return (1);
	}
	return (0);
}

void	create_box(int type, int *counter, int *item)
{
	*item = type;
	if (counter)
		*counter += 1;
}

// int	*get_map_line(char *line, t_struct *game, int c)
// {
// 	int		i;
// 	int		*map_line;

// 	i = -1;
// 	map_line = malloc(sizeof(int) * game->map_width);
// 	if (!map_line)
// 		ft_error();
// 	while (++i < game->map_width)
// 	{
// 		if (line[i] == '0')
// 			create_box(game->floor, 0, &map_line[i]);
// 		if (line[i] == '1')
// 			create_box(game->wall, 0, &map_line[i]);
// 	}
// 	return (map_line);
// }

int	ft_map_check(char *map, t_struct *game)
{
	char	*line;
	int		i;

	game->map_height = ft_height_check(map);
	game->map = malloc(sizeof(int *) * game->map_height);
	if (!game->map || (open(map, O_RDONLY) != 1))
		ft_error();
	i = -1;
	while (++i < game->map_height)
	{
		line = get_next_line(open(map, O_RDONLY));
		if (!line)
			ft_error();
		if (ft_line_ok(line, game))
			ft_error();
		// game->map[i] = get_map_line(line, game, i);
		free(line);
	}
	return (0);
}