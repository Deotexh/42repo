/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/04 17:41:24 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/04 17:41:25 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int vi_count_digits(int n) {
  int count;

  if (n == 0)
	  return (1);
  count = 0;
  while (n != 0) {
    n /= 10;
    count++;
  }
  return (count);
}

char *ft_itoa(int n) {
  int digits_count;
  int temp_digit;
  int i;
  int is_num_neg;
  char *str;

  digits_count = vi_count_digits(n);
  str = malloc(digits_count + 1 + (n < 0));
  if (!str)
    return ((void *)0);
  is_num_neg = 0;
  if (n < 0)
  {
    is_num_neg = 1;
    str[0] = '-';
  }
  i = digits_count + is_num_neg - 1;
  while (i >= is_num_neg) {
    temp_digit = (n % 10);
	if (temp_digit < 0)
		temp_digit *= -1;
	str[i] = temp_digit + '0';
    n /= 10;
    i--;
  }
  str[digits_count + is_num_neg] = '\0';
  return (str);
}
