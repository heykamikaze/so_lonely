/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbenjami <nbenjami@student.21-school.ru    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/25 20:16:53 by nbenjami          #+#    #+#             */
/*   Updated: 2021/10/26 22:15:26 by nbenjami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_getnbr(int n)
{
	int	i;

	i = 0;
	if (n <= 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*num;
	int		len;

	len = ft_getnbr(n);
	num = malloc(len + 1);
	if (!num)
		return (NULL);
	if (n == -2147483648)
		ft_strlcpy(num, "-2147483648", 12);
	if (n < 0 && n != -2147483648)
	{
		num[0] = '-';
		n = -n;
	}
	num[len] = '\0';
	if (n == 0)
		num[0] = '0';
	while (n && n != -2147483648)
	{
		num[--len] = n % 10 + '0';
		n = n / 10;
	}
	return (num);
}
