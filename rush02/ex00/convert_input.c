/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_to_queriable.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/02 15:26:29 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/02 19:32:08 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "convert_input.h"
//Mettre un if dans le main si -1 pour Error
int	get_num_set_3_zeros(int num)
{
	int	n_3zeros;

	n_3zeros = 0;
	while (1)
	{
		num /= 1000;
		if (num != 0)
			n_3zeros++;
		else
			break ;
	}
	return (n_3zeros);
}

int	get_num_entries(int num)
{
	int	n_entries;
	int	original_num;

	original_num = num;
	n_entries = 0;
	while (num != 0)
	{
		if (original_num == num && num % 10 != 0)
			n_entries += 1;
		else if (num % 10 != 0)
			n_entries += 2; 
		num /= 10;
	}
	return (n_entries);
}

int get_n_digits(int num)
{
	int ndigits;

	while (num != 0)
	{
		num /= 10;
		ndigits++;
	}
	return (ndigits);
}

void add_query_entry(char *entries, int entry, int index)
{
	int i;
	int ndigits;
	char c_digit;

	i = 0;
	ndigits = get_n_digits(entry);
	entries[index] = NULL;
	while (entries[index] == NULL)
		entries[index] = malloc(sizeof(char) * (ndigits + 1));
	while (ndigits > 0)
	{
		c_digit = (thousands_buf / ipow(10, ndigits - i + 1) % 10) + '0';
		entries[index][i] = c_digit;
		i++;
		ndigits--;
	}
	entries[index][i] = '\0';
}

char *convertNums(char *num_input)
{
	int num;
	int n_3zeros;
	int entries_i;
	int ndigits;
	int digit;
	int thousands_buf;
	char **entries;

	num = vi_atoi(num_input);
	n_3zeros = get_num_set_3_zeros(num);
	entries = malloc(sizeof(char *) * get_num_entries(num));
	entries_i = 0;
	while (n_3zeros != 0)
	{
		thousands_buf = num / ipow(1000, n_3zeros)
		ndigits = get_n_digits(thousands_buf);
		while (ndigits > 0)
		{
			digit = (thousands_buf / ipow(10, ndigits - 1)) % 10;
			if (ndigits == 1)
				add_query_entry(entries, digit, entries_i++);
			else if (ndigits == 4)
			{
				add_query_entry(entries, digit, entries_i++);
				add_query_entry(entries, ipow(1000, n_3zeros), entries_i++);
			}
			else 
			{
				add_query_entry(entries, digit, entries_i++);
				add_query_entry(entries, ipow(10, ndigits), entries_i++);
			}
		}
		n_3zeros--;
	}
}
