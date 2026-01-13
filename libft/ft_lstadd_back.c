/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 17:30:31 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:35:00 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*tmp;

	if (!new)
		return ;
	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = ft_lstlast(*lst);
	tmp->next = new;
}

/*
#include <stdio.h>
int	main()
{
	t_list	*lst = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");

	ft_lstadd_back(&lst, node2);
	while (lst)
	{
		printf("%s\n", (char *)lst->content);
		lst = lst->next;
	}
	free (lst);
	return (0);
}
*/
