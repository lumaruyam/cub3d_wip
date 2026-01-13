/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_nbr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 19:56:40 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:37:04 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_nbr(long n, int base)
{
	int		digit;
	char	*hex;

	digit = 0;
	hex = "0123456789abcdef";
	if (n < 0)
	{
		write(1, "-", 1);
		return ((ft_print_nbr(-n, base) + 1));
	}
	else if (n < base)
		return (ft_print_char(hex[n]));
	else
	{
		digit = ft_print_nbr(n / base, base);
		return (digit + ft_print_nbr(n % base, base));
	}
	return (digit);
}
