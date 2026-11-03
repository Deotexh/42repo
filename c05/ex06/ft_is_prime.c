/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:53:03 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 19:14:23 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_is_prime(int nb)
{
	int	divider;

	divider = 2;
	if (nb == 0 || nb == 1)
		return (0);
	while (divider < nb)
	{
		if (nb % divider == 0)
			return (0);
		divider++;
	}
	return (1);
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d", ft_is_prime(4));
// }
