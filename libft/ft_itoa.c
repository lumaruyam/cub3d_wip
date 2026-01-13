/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 15:04:10 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:35:01 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	ct_digit(int n)
{
	int	digit;

	digit = 0;
	if (n == 0)
		digit = 1;
	if (n < 0)
		n *= -1;
	while (n != 0)
	{
		digit++;
		n /= 10;
	}
	return (digit);
}

char	*ft_itoa(int n)
{
	char		*str;
	int			digit;
	long int	num;

	digit = ct_digit(n);
	num = n;
	if (n < 0)
	{
		digit += 1;
		num *= -1;
	}
	str = (char *)malloc(sizeof(char) * (digit + 1));
	if (!str)
		return (NULL);
	str[digit] = '\0';
	while (digit--)
	{
			str[digit] = (num % 10) + '0';
			num = num / 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}

/*
#include <stdio.h>
int	main()
{
	int	n = -10;

	printf("%s\n", ft_itoa(n));
	return (0);
}
*/
