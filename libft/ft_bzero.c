/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 19:12:58 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:35:13 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = 0;
		i++;
	}
}

/*
#include <stdio.h>
int	main()
{
	char	s[] = {'a', 'b', 'c'};
	size_t	n = 4;
	size_t	i = 0;

	ft_bzero(s, n);
	while (i < n)
	{
		printf("%d\n", s[i]);
		i++;
	}
}
*/
