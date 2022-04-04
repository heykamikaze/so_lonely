/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:39:07 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/14 17:55:39 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*s3;
	int		i;
	int		j;

	if (!s2)
		return (NULL);
	s3 = malloc((ft_strlen(s1) + ft_strlen(s2) + 1) * sizeof(char));
	if (!s3)
		return (NULL);
	i = 0;
	j = 0;
	while (s1 && s1[i])
	{
		s3[i] = s1[i];
		i++;
	}
	while (s2[j])
		s3[i++] = s2[j++];
	s3[i] = '\0';
	if (s1)
		free (s1);
	return (s3);
}

char	*ft_get_line(char *remains)
{
	char	*before_n;
	int		i;

	i = 0;
	if (!remains || !(*remains))
		return (NULL);
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	before_n = ft_substr(remains, 0, i);
	return (before_n);
}

char	*ft_get_line_after_n(char *remains)
{
	char	*after_n;
	int		i;

	i = 0;
	if (!remains)
		return (NULL);
	after_n = NULL;
	while (remains[i])
		if (remains[i++] == '\n')
			break ;
	if (remains[i] == '\0')
	{
		free(remains);
		return (NULL);
	}
	else if (remains[i - 1] == '\n')
		after_n = ft_substr(remains, i, ft_strlen(remains + i));
	free (remains);
	return (after_n);
}

char	*ft_start(int fd, char *remains)
{
	int		reader;
	char	*buffer;

	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return (NULL);
	reader = 1;
	while (reader > 0 && !ft_strchr(remains, '\n'))
	{
		reader = read(fd, buffer, BUFFER_SIZE);
		if (reader == -1)
		{
			free(buffer);
			return (NULL);
		}
		buffer[reader] = '\0';
		remains = ft_strjoin(remains, buffer);
		if (!remains)
		{
			free(buffer);
			return (NULL);
		}				
	}
	free (buffer);
	return (remains);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*remains[OPEN_MAX];

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	remains[fd] = ft_start(fd, remains[fd]);
	line = ft_get_line(remains[fd]);
	remains[fd] = ft_get_line_after_n(remains[fd]);
	return (line);
}

/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	int fd1;
	char *line;
	char *line1;
	fd = open("hello", O_RDWR);
	fd1 = open("goodbye", O_RDWR);
		if (fd < 0)
	{
		printf("open error\n");
		return (1);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			printf("end of file\n");
			break ;
		}
		printf("line: %s\n", line);
		free(line);
	}
		if (fd1 < 0)
	{
		printf("error\n");
		return (1);
	}
	while (1)
	{
		line1 = get_next_line(fd1);
		if (!line1)
		{
			printf("end of file\n");
			break ;
		}
		printf("line: %s\n", line1);
		free(line1);
	}
	close(fd);
	close(fd1);
	return(0);
}*/