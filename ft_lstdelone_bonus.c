/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 19:12:25 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/17 22:35:48 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// void delete(void *content)
// {
// 	free(content);
// }
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
	{
		return ;
	}
	del(lst->content);
	free(lst);
	lst = NULL;
}

// #include <stdio.h>

// int	main(void)
// {
// 	t_list *head;
// 	t_list	*node;
// 	t_list	*node1;
// 	t_list	*node2;
// 	int *a,*b,*c;
// 	a = (int*)malloc(sizeof(int));
// 	b = (int*)malloc(sizeof(int));
// 	c = (int*)malloc(sizeof(int));
// 	*a = 10;
// 	*b = 5;
// 	*c = 1;
// 	head = NULL;
// 	node = ft_lstnew(a);
// 	node1 = ft_lstnew(b);
// 	node2 = ft_lstnew(c);
// 	ft_lstadd_back(&head,node);
// 	ft_lstadd_back(&head,node1);
// 	ft_lstadd_back(&head,node2);
// 	t_list *temp;
// 	temp = head;
// 	while(head)
// 	{
// 		printf("%d\n",*(int *)head->content);
// 		head = head->next;
// 	}

// 	while(head){
// 		temp = head->next;
// 	ft_lstdelone(head,&delete);
// 	head = temp;
// 	}
// 	printf("list has been deleted.\n");
// 	return (0);
// }

// int main() {
//     // Creating a new node with dynamically allocated content
//     int *content = malloc(sizeof(int));
//     *content = 42; // Assign a value to the dynamically allocated memory
//     t_list *node = ft_lstnew(content);

//     // Applying ft_lstdelone to delete the node
//     ft_lstdelone(node, delete);

//     // node pointer is now dangling, we should not use it anymore

//     // Ideally, set your outside pointer to NULL after deletion if applicable
//     node = NULL;

//     // If node was not set to NULL after deletion and you tried to use it,
// it would be an error
//     // printf("%d\n", *(int *)
// 	printf("Node has been deleted.\n");

// // In practice,
// 	we cannot (and don't need to) prove that 'node' has been freed in this test program.
// //
// 	// You can use tools like valgrind to check for memory leaks and verify that free() has been correctly called.

// // return (0);
// // }
