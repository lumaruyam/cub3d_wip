/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 16:14:44 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:22 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (!s || !f)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!str)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

/*
#include <stdio.h>
char	ft_toupperr(unsigned int i, char c)
{
	(void)i;

	if (c >= 'a' && c <= 'z')
		c -= 32;
	return (c);
}

int	main()
{
	char const	s[] = "hello";
	char	*str;

	str = ft_strmapi(s, ft_toupperr);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
