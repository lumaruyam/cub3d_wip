/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 21:33:20 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:32 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strdup(const char *s)
{
	char	*d;
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	d = malloc(sizeof(char) * (i + 1));
	if (d == NULL)
		return (NULL);
	i = 0;
	while (s[i])
	{
		d[i] = s[i];
		i++;
	}
	d[i] = '\0';
	return (d);
}

/*
#include <stdio.h>
int	main(void)
{
	char	s[] = "Hello World";
	char	*d;
	char	*d2;

	d = ft_strdup(s);
	printf("%s\n", d);
	d2 = strdup(s);
	printf("%s\n", d2);
	free(d);
	free(d2);
	return (0);
}
*/
