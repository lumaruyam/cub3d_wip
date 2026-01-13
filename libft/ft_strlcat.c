/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/10 13:50:42 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:27 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d;
	size_t	s;

	i = 0;
	d = ft_strlen(dst);
	s = ft_strlen(src);
	if (dstsize <= d)
		return (s + dstsize);
	while (src[i] && (d + i) < (dstsize - 1))
	{
		dst[d + i] = src[i];
		i++;
	}
	dst[d + i] = '\0';
	return (d + s);
}

/*
#include <stdio.h>
#include <bsd/string.h>
int	main(void)
{
	char	src[] = "World";
	char	dst[] = "Hello ";
	unsigned int	size = 12;

	char	src2[] = "World";
	char	dst2[] = "Hello ";
	unsigned int	size2 = 12;

	printf("%zu\n", ft_strlcat(dst, src, size));
	printf("%s\n", dst);
	printf("%zu\n", strlcat(dst2, src2, size2));
	printf("%s\n", dst);
	return (0);
}
*/
