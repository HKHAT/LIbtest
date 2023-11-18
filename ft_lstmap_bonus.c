/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 08:33:20 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/17 22:36:05 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*node;
	t_list	*new_list;
	t_list	*set;

	if (!lst || !del || !f)
	{
		return (NULL);
	}
	new_list = NULL;
	while (lst)
	{
		set = f(lst->content);
		node = ft_lstnew(set);
		if (!node)
		{
			del(set);
			ft_lstclear(&new_list, (*del));
			return (new_list);
		}
		ft_lstadd_back(&new_list, node);
		lst = lst->next;
	}
	return (new_list);
}

// void *transform_content(void *content)
// {
//     // Check if the content pointer is valid
//     if (content == NULL) {
//         return (NULL);
// }
//     char *str = (char *)content;
//     char *result = ft_strdup(str); // Duplicate the original content
//     // Convert each character in the duplicated string to uppercase
//     for (size_t i = 0; result[i]; i++) {
//         result[i] = ft_toupper(result[i]);
//     }
//     return (result);
// }
// #include <stdio.h>
// void free_content(void *content)
// {
//     free(content);
// }
// int	main(void)
// {
// 	t_list *lst = ft_lstnew("hello");
// 	ft_lstadd_back(&lst, ft_lstnew("world"));
// 	t_list *new_lst = ft_lstmap(lst, &transform_content, &free_content);
// 	printf("%s\n",(char*)new_lst->content);
// }gcc -Wall -Werror
