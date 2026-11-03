/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/20 17:27:52 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/28 17:46:06 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	len;

	len = 0;
	while (str[len] != '\0')
	{
		++len;
	}
	return (len);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_size;

	i = 0;
	src_size = ft_strlen(src);
	while (i < size)
	{
		if (i < src_size)
			dest[i] = src[i];
		else
			dest[i] = '\0';
		++i;
	}
	dest[size - 1] = '\0';
	return (src_size);
}

#include <bsd/string.h>
#include <stdio.h>
int	main()
{
	char str[] = "Hello,qqqqqqqqqq";
	char dest[13] = "aaaaaaaaaaaa";
	char dest2[13] = "aaaaaaaaaaaa";

	printf("Custom -- \n\n");
	printf("Before: %s\n", dest);
	int returned = ft_strlcpy(dest, str, 13);
	printf("After: %s\n", dest);
	printf("Return: %d\n", returned);

	printf("\n\nOriginal --\n");
	printf("Before: %s\n", dest2);
	int returned2 = strlcpy(dest2, str, 13);
	printf("After: %s\n", dest2);
	printf("Return: %d\n", returned2);
	return 0;
}
