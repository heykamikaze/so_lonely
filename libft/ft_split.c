/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/26 17:33:43 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:20:46 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_number(const char *s, char c)
{
	size_t	i;
	size_t	n;

	i = -1;
	n = 0;
	while (s[++i])
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			n++;
	return (n);
}

static char	**ft_free(char **res)
{
	size_t	i;

	i = 0;
	while (res[i])
	{
		free(res[i]);
		i++;
	}
	free (res);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**res;
	size_t	acc;
	size_t	i;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (ft_number(s, c) + 1));
	if (!res)
		return (NULL);
	res[ft_number(s, c)] = NULL;
	acc = 0;
	i = 0;
	while (acc < ft_number(s, c))
	{
		while (s[i] == c && s[i])
			i++;
		res[acc] = ft_substr(s, i, ft_strchr(&s[i], c) - &s[i]);
		if (res[acc] == NULL)
			return (ft_free(res));
		acc++;
		i = i + ft_strchr(&s[i], c) - &s[i];
	}
	return (res);
}
