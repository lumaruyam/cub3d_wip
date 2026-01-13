/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/21 16:45:36 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/10/21 16:49:32 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

char	*ft_strndup(const char *str, int nb)
{
	char	*new;
	int		i;
	int		len;

	i = 0;
	if (!str || nb < 0)
		return (NULL);
	if ((int)ft_strlen(str) <= nb)
		len = ft_strlen(str);
	else
		len = nb;
	new = (char *)malloc(sizeof(char) * (len + 1));
	if (!new)
		return (NULL);
	while (str[i] && i < nb)
	{
		new[i] = str[i];
		i++;
	}
	new[i] = '\0';
	return (new);
}
