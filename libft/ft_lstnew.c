/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/15 20:46:04 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:42:30 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_list	*ft_lstnew(void *nb)
{
	t_list	*node;

	node = malloc(sizeof(t_list) * 1);
	if (!node)
		return (NULL);
	node->content = nb;
	node->next = NULL;
	return (node);
}

/*
#include <stdio.h>
int	main()
{
	char	new_cnt[] = "hello";
	t_list	*node;

	node = ft_lstnew((void *)new_cnt);
	printf("%s\n", (char *)node->content);
	printf("%p\n", (void *)node->next);
	free(node);
	return (0);
}
*/
