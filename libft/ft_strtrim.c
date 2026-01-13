/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 16:50:40 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:14 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	start = 0;
	end = ft_strlen(s1);
	while (ft_strchr(set, s1[start]) && start < end)
		start++;
	if (start >= end)
		return (ft_strdup(s1 + end));
	while (ft_strchr(set, s1[end - 1]) && end >= 0)
		end--;
	str = malloc(end - start + 1);
	if (!str)
		return (NULL);
	ft_strlcpy(str, &s1[start], end - start + 1);
	return (str);
}

/*
#include <stdio.h>
int	main()
{
	char const s1[] = "abHellobba";
	char const	set[] = "ab";
	char	*str;

	str = ft_strtrim(s1, set);
	printf("%s\n", str);
	free(str);
	return (0);
}
*/
