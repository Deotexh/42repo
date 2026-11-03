/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:16:08 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/24 11:42:15 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
char	*ft_strstr(char *str, char *to_find)
{
	int	compare_i;
	int	find_i;

	if (to_find[0] == '\0')
		return (str);
	find_i = -1;
	while (str[++find_i] != '\0')
	{
		compare_i = 0;
		if (str[find_i] != to_find[compare_i])
			continue ;
		while (to_find[compare_i] == str[find_i + compare_i])
		{
			if (to_find[compare_i + 1] == '\0')
				return (&str[find_i]);
			compare_i++;
		}
	}
	return ((void *)0);
}

// #include <string.h>
// #include <stdio.h>
// int main(void)
// {
// 	char hay[] = "Hello, World!";
// 	char needle[] = "";
//
// 	printf("Ft result: %s\n", ft_strstr(hay, needle));
// 	printf("Original result: %s\n", strstr(hay, needle));
// }
