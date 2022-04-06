/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/09 20:38:37 by nbenjami          #+#    #+#             */
/*   Updated: 2022/04/06 20:11:08 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*s3;
	size_t	s1_len;
	size_t	s2_len;

	if (s1 && s2)
	{
		s1_len = ft_strlen(s1);
		s2_len = ft_strlen(s2);
		s3 = (char *)malloc(s1_len + s2_len + 1);
		if (s3 == NULL)
			return (NULL);
		ft_strlcpy(s3, s1, s1_len + 1);
		ft_strlcat(s3, s2, (s1_len + s2_len + 1));
		return (s3);
	}
	return (NULL);
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
		// write(1, "sega", 5);
		remains = ft_strjoin(remains, buffer);
		// write(1, "hello", 5);
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
	static char	*remains;

	if (fd < 0 || BUFFER_SIZE < 0)
		return (NULL);
	remains = ft_start(fd, remains);
	line = ft_get_line(remains);
	remains = ft_get_line_after_n(remains);
	return (line);
}

/*#include <fcntl.h>
int	main(void)
{
	int		fd;
	char *line;
	fd = open("hello", O_RDWR);
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
			printf("end program\n");
			break ;
		}
		printf("line: -->%s--\n", line);
		free(line);
	}
	return(0);
}*/