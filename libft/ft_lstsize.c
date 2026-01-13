/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 14:08:35 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:50 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

/*
#include <stdio.h>
int	main()
{
	t_list	*lst = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");

	ft_lstadd_front(&lst, node2);
	printf("%d\n", ft_lstsize(lst));
	free (lst);
	return (0);
}
*/
