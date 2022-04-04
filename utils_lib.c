#include "so_long.h"

void	ft_putstr_fd(char *s, int fd)
{
	if (s)
		while (*s)
			write(fd, s++, 1);
}

void	ft_error(void)
{
	write(1, "Error\n", 7);
	exit(1);
}

int	ft_strlen(char *s)
{
    int	i;

    i = 0;
	while (s[i] != '\0')
    	i++;
    return (i);
}