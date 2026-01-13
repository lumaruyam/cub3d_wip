/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 17:55:53 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:47 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	d = (unsigned char *)s1;
	s = (unsigned char *)s2;
	while (i < n)
	{
		if (d[i] != s[i])
			return (d[i] - s[i]);
		i++;
	}
	return (0);
}

/*
#include <stdio.h>
int	main()
{
	const char	s1[] = "aa";
	const char	s2[] = "a";
	size_t	n = 9;

	const char	ss1[] = "aa";
	const char	ss2[] = "a";

	printf("%d\n", ft_memcmp(s1, s2, n));
	return (0);
}
*/
