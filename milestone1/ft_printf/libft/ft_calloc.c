/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 12:17:12 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 13:20:50 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stddef.h>
#include <stdlib.h>
#include <stdint.h>
#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*p;
	size_t	result;

	if (nmemb == 0 || size == 0)
	{
		p = malloc(1);
		return (p);
	}
	if (size > SIZE_MAX / nmemb)
		return (NULL);
	result = size * nmemb;
	p = malloc(result);
	ft_memset(p, 0, result);
	return (p);
}

// #include <stdio.h>
// int main()
// {
// 	size_t size = SIZE_MAX;
// 	void *ptr;
// 	size_t i;
//
// 	ptr = ft_calloc(sizeof(char) *2, size);
// 	if (!ptr)
// 		return 1;
//
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("Mine: %x\n", *((char *)ptr + i));
// 		i++;
// 	}
//
// 	free(ptr);
//
// 	ptr = calloc(sizeof(char) *2, size);
// 	if (!ptr)
// 		return 1;
//
// 	i = 0;
// 	while (i < size)
// 	{
// 		printf("Default: %x\n", *((char *)ptr + i));
// 		i++;
// 	}
//
// 	free(ptr);
// }
