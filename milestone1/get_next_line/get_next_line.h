/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:11 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/16 14:40:31 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
# include <stdlib.h>

typedef struct s_fd_read_infos
{
	char	*str;
	size_t	size;
}			t_fd_read_infos;

char		*get_next_line(int fd);
char		*vi_realloc_str(char *str, size_t old_size, size_t size);
void		vi_strlcat(char *dst, const char *src, size_t size);
int			vi_extract_excess(t_fd_read_infos *excess, char *result,
				size_t result_size);
size_t		vi_get_enough_size(size_t old_size);
char		vi_is_completeline(char *result, size_t result_size);
size_t		vi_strlen(char *str);

#endif // GET_NEXT_LINE_H
