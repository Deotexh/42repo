/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/13 10:33:11 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/13 10:33:37 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFFER_SIZE 42
char	*get_next_line(int fd);

typedef struct s_fd_read_infos
{
	char *str;
	size_t size;
	size_t offset;
	size_t bytes_read;
	int fd;
} t_fd_read_infos;

#endif // GET_NEXT_LINE_H
