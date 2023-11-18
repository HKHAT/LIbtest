/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:49:24 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/17 22:35:45 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// #include <stdio.h>
// void ft_printf(void *content)
// {
// 	printf("%d\n",*(int*)content);
// }
void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (!lst || !f)
		return ;
	while (lst)
	{
		f(lst->content);
		lst = lst->next;
	}
}

// int	main(void)
// {
// 	t_list *head;
// 	int *a= (int *)malloc(sizeof(int));
// 	int *b = (int *)malloc(sizeof(int));
// 	*a = 10;
// 	*b = 8;
// 	head = NULL;
// 	t_list *node;
// 	t_list *node1;
// 	node = ft_lstnew(a);
// 	node1 = ft_lstnew(b);
// 	ft_lstadd_back(&head,node);
// 	ft_lstadd_back(&head,node1);
// 	ft_lstiter(head,&ft_printf);
// 	return (0);
// }
