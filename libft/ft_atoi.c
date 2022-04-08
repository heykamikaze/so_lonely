/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 17:10:22 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:14:39 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int			a;
	long int	b;
	long int	negative;

	a = 0;
	b = 0;
	negative = 1;
	while ((str[a] >= 9 && str[a] <= 13) || str[a] == 32)
		a++;
	if (str[a] == 45 || str[a] == 43)
	{
		if (str[a] == 45)
			negative *= -1;
		a++;
	}
	while (str[a] >= 48 && str[a] <= 57)
	{
		b = b * 10 + (str[a] - 48);
		if (b * negative > 2147483647)
			return (-1);
		else if (b * negative < -2147483648)
			return (0);
		a++;
	}
	return (b * negative);
}
