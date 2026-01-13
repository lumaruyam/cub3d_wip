/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 14:41:41 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:16 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = ft_strlen(s);
	while (i >= 0)
	{
		if (s[i] == (char)c)
			return ((char *)s + i);
		i--;
	}
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	const char	s[6] = "hello";
	int	c = 'l';
	printf("%p\n", ft_strrchr(s, c));
	printf("%s\n", ft_strrchr(s, c));
	printf("%p\n", strrchr(s, c));
	printf("%s\n", strrchr(s, c));
	return (0);
}
*/
