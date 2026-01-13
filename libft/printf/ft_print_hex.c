/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 20:18:13 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:37:02 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_print_hex(long n, int base)
{
	int		digit;
	char	*hex;

	digit = 0;
	hex = "0123456789ABCDEF";
	if (n < 0)
	{
		write(1, "-", 1);
		return ((ft_print_hex(-n, base) + 1));
	}
	else if (n < base)
		return (ft_print_char(hex[n]));
	else
	{
		digit = ft_print_hex(n / base, base);
		return (digit + ft_print_hex(n % base, base));
	}
	return (digit);
}
