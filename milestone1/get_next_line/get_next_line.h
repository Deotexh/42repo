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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

typedef struct s_fd_read_infos
{
	char	*str;
	size_t	size;
	size_t	len;
}			t_fd_read_infos;

char		*get_next_line(int fd);
size_t		vi_get_enough_size(size_t old_size);
char		vi_is_line(t_fd_read_infos *result);
void		vi_append_buffer(t_fd_read_infos *result, char *buffer);
size_t		vi_strlen(char *str);
void		vi_clear_buffer(char *buffer, size_t start);

#endif // GET_NEXT_LINE_H
