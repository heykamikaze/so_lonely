/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/10 20:42:48 by nbenjami          #+#    #+#             */
/*   Updated: 2021/12/14 17:55:47 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s && s[i])
		i++;
	return (i);
}

int	ft_strlcpy(char *dest, char *src, int destsize)
{
	int	srcsize;
	int	destsize_1;
	int	i;

	i = 0;
	srcsize = ft_strlen(src);
	if (destsize == 0)
		return (srcsize);
	if (srcsize >= destsize)
		destsize_1 = destsize - 1;
	else
		destsize_1 = srcsize;
	while (i < destsize_1)
	{
		dest[i] = src[i];
		i++;
	}
	dest[destsize_1] = '\0';
	return (srcsize);
}

char	*ft_strchr(char *str, int c)
{
	if (str == NULL)
		return (NULL);
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	else
		return (NULL);
}

static	int	ft_min(int n, int m)
{
	if (n > m)
		return (m);
	else
		return (n);
}

char	*ft_substr(char *s, unsigned int start, int len)
{
	char	*res;
	int		p;

	if (!s)
		return (0);
	if ((int)start >= ft_strlen(s))
	{
		res = (char *)malloc(sizeof(char) * 1);
		res[0] = '\0';
		if (res == NULL)
			return (NULL);
		return (res);
	}
	p = ft_min(ft_strlen(s + start), len);
	res = (char *)malloc(sizeof(char) * (p + 1));
	if (res == NULL)
		return (NULL);
	ft_strlcpy(res, s + start, p + 1);
	return (res);
}
