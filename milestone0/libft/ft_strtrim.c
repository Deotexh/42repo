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
  int start;
  int end;
  int i;

  if (!s1 || !set)
    return ((void *)0);
  start = 0;
  while (vi_hasset(s1[start], set))
    start++;
  if (s1[start] == '\0')
  {
	  new_str = malloc(1);
	  if (!new_str)
		  return ((void *)0);
	  new_str[0] = '\0';
	  return (new_str);
  }
  end = 0;
  while (s1[end] != '\0')
	  end++;
  while (vi_hasset(s1[end - 1], set))
	  end--;
  new_str = malloc(end - start + 1);
  if (!new_str)
	  return ((void *)0);
  i = 0;
  while (i < end - start)
  {
	  new_str[i] = s1[start + i];
	  i++;
  }
  new_str[i] = '\0';
  return (new_str);
}
