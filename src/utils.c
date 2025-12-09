/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/09 20:48:36 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/12/09 20:53:51 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (n != 0)
	{
		*p = '\0';
		p++;
		n--;
	}
}

void	*ft_calloc(size_t ct, size_tb size)
{
	void	*res;

	res = malloc(ct * size);
	if (!res)
		return (NULL);
	ft_bzero(res, size * ct);
	return (res);
}
