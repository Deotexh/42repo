/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 18:16:08 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/23 21:03:23 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	char str1[] = "Hello, World!";
	char str2[] = "Helbo, World!";
	
	char str3[] = "Hello, World!";
	char str4[] = "Helbo, World!";
	printf("Ft result: %d\n", ft_strcmp(str1, str2));
	printf("Original result: %d\n", strcmp(str3, str4));
}
*/
