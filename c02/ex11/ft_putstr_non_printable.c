/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 11:01:30 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/21 11:58:42 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	vi_char_is_printable(char c)
{
	if (c < 32 || c == 127)
		return (0);
	return (1);
}

void	vi_print_char_in_hex(char c)
{
	char	temp;

	ft_putchar('\\');
	temp = c / 16;
	if (temp < 10)
		temp += '0';
	else
		temp += 'a' - 10;
	ft_putchar(temp);
	temp = c % 16;
	if (temp < 10)
		temp += '0';
	else
		temp += 'a' - 10;
	ft_putchar(temp);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (vi_char_is_printable(str[i]) == 0)
			vi_print_char_in_hex(str[i]);
		else
			ft_putchar(str[i]);
		i++;
	}
	vi_print_char_in_hex(str[i]);
}

// int	main()
// {
// 	char str[] = "Hello, \nmy\tdear World!";
//
// 	ft_putstr_non_printable(str);
// }
