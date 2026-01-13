/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 18:51:03 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:35 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

static size_t	ft_ctword(char const *s, char c)
{
	size_t	ct;
	size_t	i;

	i = 0;
	if (!s[i])
		return (0);
	ct = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
			ct++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (ct);
}

char	**ft_split(char const *s, char c)
{
	char	**lst;
	size_t	word_len;
	int		i;

	lst = (char **)malloc(sizeof(char *) * (ft_ctword(s, c) + 1));
	if (!s || !lst)
		return (0);
	i = 0;
	while (*s)
	{
		while (*s == c && *s)
			s++;
		if (*s)
		{
			if (!ft_strchr(s, c))
				word_len = ft_strlen(s);
			else
				word_len = ft_strchr(s, c) - s;
			lst[i++] = ft_substr(s, 0, word_len);
			s = s + word_len;
		}
	}
	lst[i] = NULL;
	return (lst);
}

/*
#include <stdio.h>
int	main(void)
{
	int	i;
	char const	s[] = "Lorem-ipsum-dolor-sit-amet";
	char	c = '-';
	char	**res;

	res = ft_split(s, c);
	if (res)
	{
		i = 0;
		while (res[i])
		{
			printf("%s\n", res[i]);
			free(res[i]);
			i++;
		}
		free(res);
	}
	return (0);
}
*/
