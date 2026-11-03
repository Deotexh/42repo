/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/21 12:07:08 by vitruong          #+#    #+#             */
/*   Updated: 2026/07/23 17:55:10 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <unistd.h>
#include <stdint.h>

void	vi_putchar_dot(char c)
{
	if (c < 32 || c == 127)
		write(1, ".", 1);
	else
		write(1, &c, 1);
}

char	vi_get_hex(int digit)
{
	if (digit < 10)
		return (digit + '0');
	else
		return (digit + 'a' - 10);
}

void	vi_print_char_hex(char *addr, int char_pos, int line_pos)
{
	int		temp;
	char	current_char;

	temp = addr[(char_pos + (line_pos - 1) * 16)] / 16;
	current_char = vi_get_hex(temp);
	write(1, &current_char, 1);
	temp = (addr[(char_pos + (line_pos - 1) * 16)]) % 16;
	current_char = vi_get_hex(temp);
	write(1, &current_char, 1);
}

void	vi_print_entire_address(uintptr_t addr)
{
	int		print_index;
	int		hex_index;
	char	hex_digit;
	char	hex_num[17];

	hex_index = 0;
	while (addr != 0)
	{
		hex_digit = vi_get_hex(addr % 16);
		hex_num[hex_index] = hex_digit;
		hex_index++;
		addr /= 16;
	}
	print_index = -1;
	while (++print_index < 16)
	{
		if (print_index < 16 - hex_index)
			write(1, "0", 1);
		else
			write(1, &hex_num[--hex_index], 1);
	}
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	line_i;
	unsigned int	char_i;

	line_i = 0;
	while (++line_i <= (size / 16) + (size % 16 > 0))
	{
		vi_print_entire_address((uintptr_t)addr + ((line_i - 1) * 16));
		write(1, ": ", 2);
		char_i = -1;
		while (++char_i < 16)
		{
			if (char_i >= size - (line_i - 1) * 16)
				write(1, "  ", 2);
			else
				vi_print_char_hex((char *)addr, char_i, line_i);
			if (char_i % 2 == 1)
				write(1, " ", 1);
		}
		char_i = 0;
		while (++char_i <= 16 && char_i <= size - (line_i - 1) * 16)
			vi_putchar_dot(*((char *)addr + (char_i + (line_i - 1) * 16) - 1));
		write(1, "\n", 1);
	}
	return (addr);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	x[] = "Salut a tous, comment ca vaaaaaaa enfoi nan jdec en vrai te";
// 	ft_print_memory(&x, strlen(x) + 1); 
// 	printf("\n\nOriginal address: %p", &x);
// 	return 0;
// }
