/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:47:44 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/09 19:57:40 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# define FLAG_HASH (1 << 0)
# define FLAG_DASH (1 << 1)
# define FLAG_ZERO (1 << 2)
# define FLAG_PLUS (1 << 3)
# define FLAG_BLANK (1 << 4)
# define FLAG_DOT (1 << 5)

typedef struct s_format_specs
{
	unsigned char	flags;
	unsigned int				width;
	unsigned int				precision;
}					t_format_specs;

int					ft_printf(const char *, ...) __attribute__((format(printf,
								1, 2)));
size_t				vi_print_arg(char format_type, t_format_specs infos,
						va_list *argptr);
ssize_t				vi_handle_formatspec(const char *str, size_t i,
						va_list *argptr, size_t *print_count);
size_t				vi_print_int(int arg, t_format_specs infos);
size_t				vi_print_uint(unsigned int arg, t_format_specs infos);
size_t				vi_print_hex(unsigned int arg, t_format_specs infos,
						char format_type);
size_t				vi_print_ptr(void *arg, t_format_specs infos);
size_t				vi_print_str(char *arg, t_format_specs infos);
size_t				vi_print_char(unsigned char arg, t_format_specs infos);
void				vi_print_alignment(int count, char c);
size_t				vi_putnbr_fd_uint(long nbr, int fd);
size_t				vi_recursive_hex_print(size_t nbr, int is_useupcase);
unsigned int		vi_count_digits_hex(size_t n);
unsigned int		vi_count_digits_int(int n);
unsigned int		vi_count_digits_uint(unsigned int n);

#endif // FT_PRINTF_H
