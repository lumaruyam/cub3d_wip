/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 18:58:50 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/10/26 15:01:49 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <string.h>
# include "get_next_line.h"

int	ft_printf(const char *str, ...);
int	ft_print_char(int c);
int	ft_print_str(char *str);
int	ft_print_nbr(long n, int base);
int	ft_print_hex(long n, int base);
int	ft_print_ptr(long unsigned n);

#endif
