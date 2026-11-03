/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 19:12:17 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/01 18:14:23 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	result;

	if (nb < 0)
		return (0);
	else if (nb == 0)
		return (1);
	result = nb;
	nb--;
	while (nb > 0)
	{
		result *= nb;
		nb--;
	}
	return (result);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d", ft_iterative_factorial(5));
// }
