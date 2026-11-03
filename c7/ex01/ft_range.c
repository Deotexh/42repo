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

int	*ft_range(int min, int max)
{
	int	*arr;
	int	i;

	if (min >= max)
		return (NULL);
	while (1)
	{
		arr = malloc(sizeof(int) * (max - min));
		if (arr != NULL)
			break ;
	}
	i = 0;
	while (i < max - min)
	{
		arr[i] = i;
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main()
// {
// 	int min = 0;
// 	int max = 9;
//
// 	int *arr = ft_range(min, max);
// 	int i = 0;
// 	while (i < max - min)
// 	{
// 		printf("%d, ", arr[i]);
// 		i++;
// 	}
// }
