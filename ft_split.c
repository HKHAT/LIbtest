/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: elchakir <elchakir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/02 10:32:03 by elchakir          #+#    #+#             */
/*   Updated: 2023/11/18 18:32:02 by elchakir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_kelma(const char *s, char c)
{
	int	i;
	int	count;

	count = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (i == 0 || s[i - 1] == c))
			count++;
		i++;
	}
	return (count);
}

static void	ft_hayed(char **array)
{
	char	**temp;

	if (array != NULL)
	{
		temp = array;
		while (*temp != NULL)
		{
			free(*temp);
			temp++;
		}
		free(array);
	}
}
static char	*alloc_kelma(const char *start, const char *end)
{
	size_t	len;
	size_t	i;
	char	*kelma;

	i = 0;
	len = end - start;
	kelma = (char *)malloc((len + 1) * sizeof(char));
	if (!kelma)
		return (NULL);
	while (i < len)
	{
		kelma[i] = start[i];
		i++;
	}
	kelma[len] = '\0';
	return (kelma);
}

static char **ft_walo(const char *s,char **split,char c,size_t len)
{
	size_t	i;
	const char	*start;

	i = 0;
	while (i < len)
	{
		while (*s == c)
			s++;
		start = s;
		while (*s && *s != c)
			s++;
		split[i] = alloc_kelma(start, s);
		if (!split[i])
		{
			ft_hayed(split);
			return (NULL);
		}
		i++;
	}
	split[i] = NULL;
	return split;
}

static char	**ft_sarokh(const char *s, char c)
{
	size_t		len;
	char		**split;

	len = count_kelma(s, c);
	split = (char **)malloc((len + 1) * sizeof(char *));
	if (!split)
		return (NULL);

	return (ft_walo(s,split,c,len));
}

char	**ft_split(const char *s, char c)
{
	char	**split;

	if (!s)
		return (NULL);
	split = ft_sarokh(s, c);
	if (split == NULL)
		return (NULL);
	return (split);
}
// #include <stdio.h>
// int	main(void)
// {
// 	// char *str = "\0aa\0bbb";
// 	// char c= '\0';
// 	char **split = ft_split("hello!zzzzzzzz",'z');
// ft_split("hello!zzzzzzzz",'z');
// 	int i;
// 	i = 0;
// 		if(split!= NULL)
// 			{
// 			while(split[i] != NULL)
// 		{
// 			printf("%s\n len = %d\n",split[i],i);

// 			i++;

// 		}
//    i = 0;
// 		while(split[i] != NULL)
// 		{
// 		free(split[i]);
// 		i++;
// 		}
// 		free(split);
// 		split = NULL;
//  		}
// 	return (0);
// }
// #include <stdio.h>
// #include <stdlib.h>

// // ... (your ft_split and other helper functions here)

// int	main(void)
// {
//     char **kelmas;
//     char *test_strings[] = {
//         "",
//         "abc",
//         "abc def",
//         "   abc def ghi   ",
//         "---split---by-hyphens---",
//         "nodividerhere",
//         "a b c d e f g h i j k l m n o p",
//         NULL
//     };
//     char dividers[] = {
//         ' ',
//         '-',
//         'x',
//         '\0'  // End of dividers array
//     };

//     for (int i = 0; test_strings[i] != NULL; i++)
//     {
//         for (int j = 0; dividers[j] != '\0'; j++)
//         {
//             printf("Test case #%d: Splitting by '%c' on \"%s\"\n", i + 1,
// dividers[j], test_strings[i]);
//             kelmas = ft_split(test_strings[i], dividers[j]);
//             if (kelmas == NULL)
//             {
//                 printf("No kelmas found or memory allocation failed.\n\n");
//                 continue ;
//             }

//             // Printing the kelmas
//             for (int k = 0; kelmas[k] != NULL; k++)
//             {
//                 printf("[%d] %s\n", k, kelmas[k]);
//             }

//             // Freeing the kelmas
//             for (int k = 0; kelmas[k] != NULL; k++)
//             {
//                 free(kelmas[k]);
//             }
//             free(kelmas); // Free the array of strings itself

//             printf("\n");
// Add a newline for better readability between test cases
//         }
//     }

//     return (0);
// }

// #include <stdio.h>

// #include <stdio.h>
// #include <stdlib.h>

// int main(int argc, char *argv[]) {
//   char **result = ft_split(argv[1], argv[2][0]);

//   for (int i = 0; result[i] != NULL; i++) {
//     printf("%s ", result[i]);
//   }
//   int i = 0;
//   while(result[i])
//   {
// 	free(result[i]);
// 	i++;
//   }
//   free(result);

//   return (0);
// }
