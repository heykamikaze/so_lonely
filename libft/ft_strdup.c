/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 21:53:36 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:22:15 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	size_t	len;
	void	*new;

	len = ft_strlen (s) + 1;
	new = malloc (len);
	if (new == NULL)
		return (NULL);
	return ((char *) ft_memcpy (new, s, len));
}
