/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdockes <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/18 09:18:25 by tdockes           #+#    #+#             */
/*   Updated: 2026/07/18 16:11:32 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	rush(int x, int y);

void	ft_putchar(char c);

int	main(void)
{
	ft_putchar('1');
	ft_putchar('\n');
	rush(2, 2);
	ft_putchar('\n');
	ft_putchar('2');
	ft_putchar('\n');
	rush(10, 5);
	ft_putchar('\n');
	ft_putchar('3');
	ft_putchar('\n');
	rush(1, 0);
	ft_putchar('\n');
	ft_putchar('4');
	ft_putchar('\n');
	rush(0, 1);
	ft_putchar('\n');
	ft_putchar('5');
	ft_putchar('\n');
	rush(0, 0);
	ft_putchar('\n');
	ft_putchar('6');
	ft_putchar('\n');
	rush(1, 1);
	return (0);
}
