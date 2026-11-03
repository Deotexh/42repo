#include <stdlib.h>

static int vi_count_digits(int n) {
  int count;

  count = 0;
  while (n > 0) {
    n /= 10;
    count++;
  }
  return (count);
}

char *ft_itoa(int n) {
  int digits_nb;
  int i;
  int is_num_neg;
  char *str;

  digits_nb = vi_count_digits(n);
  str = malloc(digits_nb + 1 + (n < 0));
  if (!str)
    return ((void *)0);
  is_num_neg = 0;
  if (n < 0) {
    is_num_neg = 1;
    str[0] = '-';
    n *= -1;
  }
  i = digits_nb + is_num_neg - 1;
  while (i >= is_num_neg) {
    str[i] = (n % 10) + '0';
    n /= 10;
    i--;
  }
  str[digits_nb + is_num_neg] = '\0';
  return (str);
}
