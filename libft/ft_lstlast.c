/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 15:46:25 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:54 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst)
	{
		if (!lst->next)
			return (lst);
		lst = lst->next;
	}
	return (lst);
}

/*
#include <stdio.h>
int	main()
{
	t_list	*lst = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");

	ft_lstadd_front(&lst, node2);
	printf("%s\n", (char *)ft_lstlast(lst)->content);
	free (lst);
	return (0);
}
*/
