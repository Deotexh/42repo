#include <stdlib.h>

static int vi_count_substrs(char const *s, char c) {
  int i;
  int len;

  i = 0;
  len = 0;
  while (s[i] != '\0') {
    if (s[i] == c && s[i + 1] != '\0' && i > 0)
      len++;
    i++;
  }
  return (len);
}

static char *vi_get_split(char const *s, char c, int *i) {
  char *ptr;
  int start;
  char write_i;

  start = *i;
  while (s[*i] != c)
    *i += 1;

  ptr = malloc(start - *i + 1);
  if (!ptr)
    return ((void *)0);
  write_i = 0;
  while (start < *i) {
    ptr[write_i] = s[start];
    write_i++;
    start++;
  }
  ptr[write_i] = '\0';
  return (ptr);
}

static void vi_free_all(char **array, int arr_i) {
  arr_i--;
  while (arr_i >= 0) {
    free(array[arr_i]);
    arr_i--;
  }
  free(array);
}

char **ft_split(char const *s, char c) {
  char **array;
  char *temp_i;
  int arr_i;
  int str_i;

  if (!s)
    return ((void *)0);
  array = malloc((vi_count_substrs(s, c) + 1) * sizeof(char *));
  str_i = 0;
  while (s[str_i] != '\0') {
    while (s[str_i] == c)
      str_i++;
    if (s[str_i] == '\0')
      break;
    temp_i = vi_get_split(s, c, &str_i);
    if (!temp_i) {
      vi_free_all(array, arr_i);
      return ((void *)0);
    }
    array[arr_i] = temp_i;
    arr_i++;
  }
  array[arr_i] = (void *)0;
  return (array);
}
