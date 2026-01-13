/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 20:38:11 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:35:15 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	ptr = malloc(nmemb * size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, nmemb * size);
	return (ptr);
}

/*
#include <stdio.h>
int	main(void)
{
	size_t	nmemb = 0;
	size_t	size = 0;
	void	*dst;
	void	*dst2;

	dst = ft_calloc(nmemb, size);
	printf("%p\n", dst);
	dst2 = calloc(nmemb, size);
	printf("%p\n", dst2);
	if (memcmp(dst, dst2, nmemb * size) == 0)
		printf("same\n");
	else
		printf("not same\n");
	free(dst);
	free(dst2);
	return (0);
}
*/
