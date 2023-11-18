/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 21:21:41 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/18 18:15:08 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void delete(void *content)
// {
// 	free(content);
// }
void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!lst || !(*lst) || !del)
	{
		return ;
	}
	temp = *lst;
	while (*lst)
	{
		temp = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		*lst = temp;
	}
}

// Assume the t_list
//structure and a delete function
// are defined correctly above this point
// #include <stdio.h>
// int main() {
//     t_list *head = NULL; // Start with an empty list
// 	t_list	*node;
// 	t_list *node1;
// 	int *a = (int *)malloc(sizeof(int));
// 	int *b = (int *)malloc(sizeof(int));
// 	*a = 10;
// 	*b = 5;
// 	node = ft_lstnew(a);
// 	node1 = ft_lstnew(b);
// 	ft_lstadd_back(&head,node);
// 	ft_lstadd_back(&head,node1);
//     // Create and add a few nodes to the list,
// presumably with dynamically allocated content
//     // ...

//     // Now clear the list using ft_lstclear
//     ft_lstclear(&head, delete);

//     // After ft_lstclear, list should be NULL
//     if (head == NULL) {
//         printf("The list was cleared successfully.\n");
//     } else {
//         printf("The list was NOT cleared.\n");
//     }

//     return (0);
// }
