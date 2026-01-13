/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 13:42:15 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:34 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;
	char			cc;

	cc = (char) c;
	i = 0;
	while (s[i])
	{
		if (s[i] == cc)
			return ((char *) &s[i]);
		i++;
	}
	if (s[i] == cc)
		return ((char *) &s[i]);
	return (NULL);
}

/*
#include <stdio.h>
int	main()
{
	const char	s[6] = "hello";
	int	c = 'l';
	printf("%p\n", ft_strchr(s, 't' + 256));
	printf("%p\n", ft_strchr(s, c));
	printf("%s\n", ft_strchr(s, c));
	printf("%p\n", strchr(s, c));
	printf("%s\n", strchr(s, c));
	return (0);
}
*/
