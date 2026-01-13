/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:01:34 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:35:10 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	ft_atoi(const char *nptr)
{
	size_t	i;
	size_t	n;
	int		sign;

	i = 0;
	n = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == 32)
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (nptr[i] && (nptr[i] >= '0' && nptr[i] <= '9'))
	{
		n = (n * 10) + (nptr[i] - '0');
		i++;
	}
	return (n * sign);
}

/*
#include <stdio.h>
int	main(int ac, char *av[])
{
	if (ac == 2)
	{
		printf("%d\n", ft_atoi(av[1]));
		printf("%d\n", atoi(av[1]));
	}
}
*/
