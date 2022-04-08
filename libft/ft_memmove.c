/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/11 02:41:40 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:17:59 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	size_t			i;

	if ((src == NULL) && (dest == NULL))
		return (NULL);
	if (dest > src)
	{
		i = len - 1;
		while (i < len)
		{
			*((unsigned char *)dest + i) = *((unsigned const char *)src + i);
			i--;
		}
	}
	else
	{
		i = 0;
		while (i < len)
		{
			*((unsigned char *)dest + i) = *((unsigned const char *)src + i);
			i++;
		}
	}
	return (dest);
}
