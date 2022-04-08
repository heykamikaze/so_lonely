/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/15 15:42:11 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:36:11 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t destsize)
{
	size_t	srcsize;
	size_t	destsize_1;

	srcsize = ft_strlen(src);
	if (destsize == 0)
	{
		return (srcsize);
	}
	if (srcsize >= destsize)
	{
		destsize_1 = destsize - 1;
	}
	else
	{
		destsize_1 = srcsize;
	}
	ft_memcpy(dest, src, destsize_1);
	dest[destsize_1] = '\0';
	return (srcsize);
}
