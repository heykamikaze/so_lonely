/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/20 15:04:41 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:15:48 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				counter;
	unsigned const char	*str;

	str = s;
	counter = 0;
	if (n == 0)
		return (0);
	while (counter < n)
	{
		if (str[counter] == (unsigned char)c)
			return ((void *)&str[counter]);
		s++;
		counter++;
	}
	return (NULL);
}
