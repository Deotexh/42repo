/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/05 16:28:18 by vitruong          #+#    #+#             */
/*   Updated: 2026/08/05 16:49:35 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include <stdlib.h>

int	vi_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	return (0);
}

int	vi_count_words(char *str, char *charset)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (!vi_is_sep(str[i], charset) && vi_is_sep(str[i - 1], charset))
			count++;
		i++;
	}
	return (count);
}

char	*vi_sep_word(char *str, char *charset)
{
	char	*word;
	int		i;
	int		len;

	len = 0;
	while (!vi_is_sep(str[len], charset) && str[len] != '\0')
		++len;
	word = NULL;
	while (word == NULL)
		word = malloc(sizeof(char) * (len + 1));
	i = 0;
	while (!vi_is_sep(str[i], charset) && str[i] != '\0')
	{
		word[i] = str[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char	**ft_split(char *str, char *charset)
{
	char	**arr;
	int		arr_i;
	int		i;

	arr_i = 0;
	arr = NULL;
	while (arr == NULL)
		arr = malloc(sizeof(char *) * (vi_count_words(str, charset) + 1));
	i = 0;
	while (str[i] != '\0')
	{
		if (!vi_is_sep(str[i], charset) && (vi_is_sep(str[i - 1], charset)
				|| i == 0))
		{
			arr[arr_i] = vi_sep_word(&str[i], charset);
			arr_i++;
		}
		i++;
	}
	return (arr);
}

// #include <stdio.h>
// int	main()
// {
// 	char **arr;
// 	int i;
//
// 	i = 0;
// 	arr = ft_split("", "");
// 	while (arr[i] != NULL)
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}
// }
