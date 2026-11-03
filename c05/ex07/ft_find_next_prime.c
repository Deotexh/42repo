/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/30 13:53:03 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/30 19:15:00 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	vi_cycle_divider(int nb)
{
	int	divider;

	divider = 2;
	while (divider < nb / 2)
	{
		if (nb % divider == 0)
			return (-1);
		divider++;
	}
	return (nb);
}

int	ft_find_next_prime(int nb)
{
	int	result;

	while (1)
	{
		result = vi_cycle_divider(nb);
		if (result != -1 && result > 1)
			return (nb);
		nb++;
	}
}

// #include <stdio.h>
// int	main()
// {
// 	printf("%d", ft_find_next_prime(11));
// }
