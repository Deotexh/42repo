/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/02 12:52:21 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 15:12:41 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int	i;

	if (n == 0)
		return (dest);
	if (dest >= src && dest <= src + n - 1)
	{
		i = n - 1;
		while (i >= 0)
		{
			*((char *)dest + i) = *((char *)src + i);
			i--;
		}
		return (dest);
	}
	i = 0;
	while (i < (int)n)
	{
		*((char *)dest + i) = *((char *)src + i);
		i++;
	}
	return (dest);
}

// #include <string.h>
// #include <stdlib.h>
// #include <stdio.h>
// int main()
// {
// 	char *str = "Bonjoureux";
// 	int offset = 9;
// 	void *p = malloc(sizeof(char) * 20);
// 	int i = 0;
// 	while (str[i])
// 	{
// 		*((char *)p + i) = str[i];
// 		i++;
// 	}
// 	ft_memmove(p + offset, p, 10);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("Dest:%X", *(char *)(p + i));
// 		printf("VS Src:%X", *(char *)(p + offset + i));
// 		printf(": %d\n", *(char *)(p + i) == *(char *)(p + offset + i));
// 		i++;
// 	}
// 	free(p);
// 	printf("\n\n");
//
// 	p = malloc(sizeof(char) * 20);
// 	i = 0;
// 	while (str[i])
// 	{
// 		*((char *)p + i) = str[i];
// 		i++;
// 	}
// 	memmove(p + offset, p, 10);
// 	i = 0;
// 	while (i < 10)
// 	{
// 		printf("Dest:%X", *(char *)(p + i));
// 		printf("VS Src:%X", *(char *)(p + offset + i));
// 		printf(": %d\n", *(char *)(p + i) == *(char *)(p + offset + i));
// 		i++;
// 	}
// 	free(p);
// }
