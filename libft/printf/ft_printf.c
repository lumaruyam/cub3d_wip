/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 19:04:27 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:36:16 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

int	ft_fmt(va_list ap, const char fmt)
{
	int	len;

	len = 0;
	if (fmt == 'c')
		len = ft_print_char(va_arg(ap, int));
	else if (fmt == 's')
		len += ft_print_str(va_arg(ap, char *));
	else if (fmt == 'd')
		len += ft_print_nbr(va_arg(ap, int), 10);
	else if (fmt == 'i')
		len += ft_print_nbr((long)va_arg(ap, int), 10);
	else if (fmt == 'u')
		len += ft_print_nbr(va_arg(ap, unsigned int), 10);
	else if (fmt == 'x')
		len += ft_print_nbr((long)va_arg(ap, unsigned int), 16);
	else if (fmt == 'X')
		len += ft_print_hex((long)va_arg(ap, unsigned int), 16);
	else if (fmt == 'p')
		len += ft_print_ptr((long unsigned)(va_arg(ap, void *)));
	else
		len += write(1, &fmt, 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		i;
	int		len;

	i = 0;
	len = 0;
	if (!str)
		return (-1);
	va_start(ap, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			len += ft_fmt(ap, str[i + 1]);
			i++;
		}
		else
			len += write(1, &str[i], 1);
		i++;
	}
	va_end(ap);
	return (len);
}
