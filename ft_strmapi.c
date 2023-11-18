/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 08:35:51 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/15 10:49:13 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// char	uppercase(unsigned int i, char c)
// {
// 	if (i % 2 == 0)
// 		return (ft_toupper(c));
// 	else
// 		return (ft_tolower(c));
// }

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	i = 0;
	str = (char *)malloc(ft_strlen(s) + 1);
	if (!str)
	{
		return (NULL);
	}
	while (s[i])
	{
		str[i] = (*f)(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char *s = ft_strmapi("MEHDI",&uppercase);
// 	printf("%s\n",s);
// }
