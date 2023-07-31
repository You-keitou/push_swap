/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:03:54 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/22 22:59:28 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>
# define BUFFERSIZE 1024

typedef struct t_buffer
{
	char	buffer[BUFFERSIZE];
	size_t	len;
	ssize_t	ret;
}			t_buffer;

int			ft_printf(const char *fmt, ...);
void		ft_fflush(t_buffer *Buffer);
void		ft_putchar(t_buffer *Buffer, char c);
void		ft_putstr(t_buffer *Buffer, char *str);
void		itoa_ten(int num, t_buffer *Buffer);
void		itoa_unsigned(int num, t_buffer *Buffer);
void		itoa_x(unsigned int num, char *base, t_buffer *Buffer);
void		convert_p(uintptr_t num, char *base, t_buffer *Buffer);
#endif