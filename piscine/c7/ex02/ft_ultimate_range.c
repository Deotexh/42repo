/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:53:34 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 20:03:36 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	*range = malloc(sizeof(int) * (max - min));
	if (*range == NULL)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = i;
		i++;
	}
	return (max - min);
}

// #include <stdio.h>
// int	main()
// {
// 	int min = 0;
// 	int max = 9;
// 	int result;
//
// 	int *arr;
// 	result = ft_ultimate_range(&arr, min, max);
// 	int i = 0;
// 	printf("%d\n", result);
// 	while (i < max - min)
// 	{
// 		printf("%d, ", arr[i]);
// 		i++;
// 	}
// }
