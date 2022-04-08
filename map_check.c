#include "so_long.h"


// int	ft_height_check(char *map)
// {
// 	// int		fd;
// 	int		height;
// 	char	*line;

// 	height = 0;
// 	while (open(map, O_RDONLY) == 1)
// 	{
// 		line = get_next_line(1);
// 		if (!line)
// 			break ;
// 		height++;
// 		free(line);
// 	}
// 	// close(fd);
// 	return (height);
// }

// int	ft_line_ok(char *line, t_struct *game)
// {
// 	int	len;
// 	int	i;

// 	len = ft_strlen(line);
// 	if (line[len - 1] == '\n')
// 	{
// 		line[len - 1] = '\0';
// 		len--;
// 	}
// 	game->map_width = len;
// 	i = -1;
// 	while (++i < len)
// 	{
// 		if (i == 0 || len - i == 1 || i == game->map_height - 1)
// 			if (line[i] != 49)
// 				return (1);
// 		if (line[i] != 48 && line[i] != 49 && line[i] != 67
// 			&& line[i] != 69 && line[i] != 80)
// 			return (1);
// 	}
// 	return (0);
// }

// void	create_box(int type, int *counter, int *item)
// {
// 	*item = type;
// 	if (counter)
// 		*counter += 1;
// }

// // int	*get_map_line(char *line, t_struct *game, int c)
// // {
// // 	int		i;
// // 	int		*map_line;

// // 	i = -1;
// // 	map_line = malloc(sizeof(int) * game->map_width);
// // 	if (!map_line)
// // 		ft_error();
// // 	while (++i < game->map_width)
// // 	{
// // 		if (line[i] == '0')
// // 			create_box(game->floor, 0, &map_line[i]);
// // 		if (line[i] == '1')
// // 			create_box(game->wall, 0, &map_line[i]);
// // 	}
// // 	return (map_line);
// // }

// int	ft_map_check(char *map, t_struct *game)
// {
// 	char	*line;
// 	int		i;

// 	game->map_height = ft_height_check(map);
// 	game->map = malloc(sizeof(int *) * game->map_height);
// 	if (!game->map || (open(map, O_RDONLY) != 1))
// 		ft_error();
// 	i = -1;
// 	while (++i < game->map_height)
// 	{
// 		line = get_next_line(open(map, O_RDONLY));
// 		if (!line)
// 			ft_error();
// 		if (ft_line_ok(line, game))
// 			ft_error();
// 		// game->map[i] = get_map_line(line, game, i);
// 		free(line);
// 	}
// 	return (0);
// }

#include "so_long.h"


int	ft_line_ok(char *line)//check C E P count collectables
{
	int	len;
	int	i;

	len = ft_strlen(line);
	if (line[len - 1] == '\n')
	{
		line[len - 1] = '\0';
		len--;
	}
	i = -1;
	while (++i < len)
	{
		if (i == 0 || len - i == 1)
			if (line[i] != 49)
				return (1);
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C' && line[i] != 'P' && line[i] != 'E')
			return (1);
	}
	return (0);
}

void	ft_check_name(char *map)
{
	int name;
	// int position;

	name = ft_strlen(map);
	// ft_putstr_fd("map name error\n", 1);
	if (map[name - 4] != '.' || map[name - 3] != 'b' || map[name - 2] != 'e' || map[name - 1] != 'r' || map[name] != '\0')
		{
			ft_putstr_fd("map name error\n", 1);
			ft_error();
		}
}

void	check_player(t_struct *game)//include in map check
{
	int i;
	int j;
	int	count_p;
	count_p = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == 'P')
			{
				game->p_x = j;
				game->p_y = i;
				count_p++;
			}
			if (game->map[i][j] == 'C')
				game->col_count++;
			j++;
		}
		i++;
	}
	// printf("%d, %d", game->p_x, game->p_y);
	if (count_p != 1)
		ft_error();
}

char *ft_collect_map(int fd, char *line)
{
	int rd;
	char readed[BUFFER_SIZE + 1];
	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, readed, BUFFER_SIZE);
		if (rd == -1)
		{
			if (line)
				free (line);
			return(NULL);
		}
		readed[rd] = '\0';
		line = ft_strjoin(line, readed);
		if (!line)
			return(NULL);
	}
	return (line);
}

int	ft_height_check(char *line, t_struct *game)
{
	int i;
	int j;
	char *checked;

	i = 0;
	j = 0;
	checked = ft_strtrim(line, "\n");
	free(line);
	while (checked[i])
	{
		if (checked[i] == '\n')
			j++;
		i++;
	}
	game->map = ft_split(checked, '\n');
	i = 0;
	while (game->map[i])
		i++;
	if (i != j + 1)
		ft_error();
	game->map_height = j + 1;
	return(1);
}

int	ft_width_check(t_struct *game)
{
	size_t	check;
	int i;

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
	int fd;
	char *line;

	game->col_count = 0;
	line = NULL;
	i = -1;
	fd = open(map, O_RDONLY);
	ft_check_name(map);
	line = ft_collect_map(fd, line);
	ft_height_check(line, game);
	game->map_width = ft_width_check(game);
	check_player(game);
	while (game->map[++i])
		{
			if (ft_line_ok(game->map[i]) == 1)
			ft_error();
		}
	// 	write(1, game->map[i], ft_strlen(game->map[i]));
	return (0);
}

// int	ft_map_check(char *map, t_struct *game)
// {
// 	char	*line;
// 	int		i;
// 	int fd;
// 	ft_putstr_fd(map, 1);
// 	ft_check_name(map);
// 	fd = open(map, O_RDONLY);
// 	if (fd < 0)
// 		ft_error();
// 	ft_collect_map(fd, line);
	