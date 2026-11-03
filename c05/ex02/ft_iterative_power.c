/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:08:41 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 12:16:27 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
	{
		return (1);
	}
	result = nb;
	power--;
	while (power > 0)
	{
		result *= nb;
		power--;
	}
	return (result);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d", ft_iterative_power(5, 3));
// }
