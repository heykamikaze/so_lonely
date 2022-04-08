/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:56:48 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:41:46 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(const char *s1, const char *set)
{
	char		*result;
	size_t		begin;
	size_t		end;

	if (s1 == NULL)
		return (NULL);
	if (set == NULL)
		return ((char *)s1);
	begin = 0;
	while (s1[begin] && ft_strchr(set, s1[begin]))
		begin++;
	end = ft_strlen(s1) - 1;
	while (end > begin && ft_strchr(set, s1[end]))
		end--;
	result = ft_substr(s1, begin, (end - begin + 1));
	return (result);
}
