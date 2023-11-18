/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 12:59:00 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/17 22:35:42 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
// #include <stdio.h>
// int	main(void)
// {
// 	t_list *head;
// 	t_list *node;
// 	t_list *node1;
// 	t_list *node2;
// 	head = NULL;
// 	node = ft_lstnew(10);
// 	node1 = ft_lstnew(9);
// 	node2 = ft_lstnew(8);
// 	ft_lstadd_back(&head,node);
// 	ft_lstadd_back(&head,node1);
// 	ft_lstadd_back(&head,node2);
// 	t_list *last = ft_lstlast(head);

// 	printf("%d\n",last->content);

// 	return (0);
// }
