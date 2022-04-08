/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 20:54:28 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:41:49 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	size_t	ft_min(size_t n, size_t m)
{
	if (n > m)
		return (m);
	else
		return (n);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*res;
	size_t	p;

	if (!s)
		return (0);
	if ((size_t)start >= ft_strlen(s))
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
