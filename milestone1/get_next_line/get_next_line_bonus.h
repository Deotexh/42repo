/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:11 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/18 18:47:37 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include <stdlib.h>

# define BUF_SET 1
# define BUF_REM 2

typedef struct s_fd_read_infos
{
	char			*str;
	size_t			size;
	size_t			offset;
	int				fd;
}					t_fd_read_infos;

typedef struct s_fd_infos_storer
{
	t_fd_read_infos	*buffers;
	size_t			size;
	size_t			offset;
	char			error_occured;
}					t_fd_infos_storer;

char				*get_next_line(int fd);
size_t				vi_get_enough_size(size_t old_size);
char				vi_is_line(t_fd_read_infos *result);
size_t				vi_strlen(char *str);
void				vi_copy(char *dst, char *src, size_t len);
ssize_t	vi_get_index_from_fd(t_fd_infos_storer *arr, int fd);
void	vi_manage_buffers(t_fd_infos_storer *arr, size_t index,
		unsigned char op_code, int fd);

#endif // GET_NEXT_LINE_BONUS_H
