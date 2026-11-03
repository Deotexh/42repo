/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/03 17:45:31 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/03 17:53:22 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

static int vi_hasset(char const c, char const *set) {
  int i;
  i = 0;
  while (set[i] != '\0') {
    if (set[i] == c)
      return (1);
    i++;
  }
  return (0);
}

char *ft_strtrim(char const *s1, char const *set) {
  char *new_str;
  int len;
  int i;
  int write_i;

  if (!s1)
    return ((void *)0);
  len = 0;
  i = 0;
  while (s1[i] != '\0') {
    if (vi_hasset(s1[i], set) == 0)
      len++;
    i++;
  }
  new_str = malloc(len + 1);
  if (!new_str)
    return ((void *)0);
  i = 0;
  write_i = 0;
  while (s1[i] != '\0') {
    if (vi_hasset(s1[i], set) == 0) {
      new_str[write_i] = s1[i];
      write_i++;
    }
    i++;
  }
  new_str[write_i + 1] = '\0';
  return (new_str);
}
