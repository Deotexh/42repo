/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vitruong <vitruong@student.42mulhouse.fr>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/11/06 13:47:44 by vitruong          #+#    #+#             */
/*   Updated: 2026/11/06 13:48:31 by vitruong         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
#define FT_PRINTF_H

#include <stdlib.h>
#include <unistd.h>

#define FLAG_HASHTAG (1 << 0)
#define FLAG_DASH (1 << 1)
#define FLAG_ZERO (1 << 2)
#define FLAG_PLUS (1 << 4)
#define FLAG_BLANK (1 << 8)

typedef struct s_format_specs
{
  unsigned char flags;
  int width;
  int precision;
} t_format_specs;

int ft_printf(const char *, ...);

#endif // FT_PRINTF_H
