/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lulmaruy <lulmaruy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 21:23:15 by lulmaruy          #+#    #+#             */
/*   Updated: 2025/09/25 18:34:55 by lulmaruy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "inc/libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		(*f)(lst->content);
		lst = lst->next;
	}
}

/*
#include <stdio.h>
void	ft_test(void *content)
{
	char	*c = (char *)content;
	int	i = 32;

	*c = *c - i;
}

int	main()
{
	t_list	*lst = ft_lstnew("node1");
	t_list	*node2 = ft_lstnew("node2");

	ft_lstadd_front(&lst, node2);
	ft_lstiter(lst, ft_test);

	t_list	*tmp = lst;
	while (tmp)
	{
		printf("%s\n", (char *)tmp->content);
		tmp = tmp->next;
	}
	t_list *current = lst;
	t_list *next;
	while (current) {
		next = current->next;
		free(current->next);
		free(current);
		current = next;
	}
	return (0);
}
*/
