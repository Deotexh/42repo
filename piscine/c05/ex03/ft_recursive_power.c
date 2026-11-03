/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_recursive_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 12:08:41 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 12:17:50 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_recursive_power(int nb, int power)
{
	int	result;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	result = nb;
	return (result * ft_recursive_power(nb, power - 1));
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d", ft_recursive_power(5, 3));
// }
