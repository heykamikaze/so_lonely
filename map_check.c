/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/10 19:16:46 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/10 21:37:57 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_line_ok(char *line)
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
		if (line[i] != '0' && line[i] != '1' && line[i] != 'C'
			&& line[i] != 'P' && line[i] != 'E' && line[i] != 'B')
			return (1);
	}
	return (0);
}

void	ft_check_name(char *map)
{
	int	name;

	name = ft_strlen(map);
	if (map[name - 4] != '.' || map[name - 3] != 'b' || map[name - 2] != 'e'
		|| map[name - 1] != 'r' || map[name] != '\0')
	{
		ft_putstr_fd("map name error\n", 1);
		ft_error();
	}
}

void	ft_check_player(t_struct *game)
{
	int	i;
	int	j;
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
	if (count_p != 1)
		ft_error();
}

char	*ft_collect_map(int fd, char *line)
{
	int		rd;
	char	readed[BUFFER_SIZE + 1];

	rd = 1;
	while (rd > 0)
	{
		rd = read(fd, readed, BUFFER_SIZE);
		if (rd == -1)
		{
			if (line)
				free (line);
			return (NULL);
		}
		readed[rd] = '\0';
		line = ft_strjoin(line, readed);
		if (!line)
			return (NULL);
	}
	return (line);
}

int	ft_height_check(char *line, t_struct *game)
{
	int		i;
	int		j;
	char	*checked;

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
	return (1);
}
