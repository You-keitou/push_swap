/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:03:54 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 00:22:32 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static void	phase_arg(va_list arg, const char *fmt, t_buffer *buffer)
{
	if (*fmt == 'c')
		ft_putchar(buffer, va_arg(arg, int));
	else if (*fmt == 's')
		ft_putstr(buffer, va_arg(arg, char *));
	else if (*fmt == 'p')
	{
		ft_putstr(buffer, "0x");
		convert_p(va_arg(arg, uintptr_t), "0123456789abcdef", buffer);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		itoa_ten(va_arg(arg, int), buffer);
	else if (*fmt == 'u')
		itoa_unsigned(va_arg(arg, int), buffer);
	else if (*fmt == 'x')
		itoa_x(va_arg(arg, int), "0123456789abcdef", buffer);
	else if (*fmt == 'X')
		itoa_x(va_arg(arg, int), "0123456789ABCDEF", buffer);
	else if (*fmt == '%')
		ft_putchar(buffer, '%');
}

void	ft_vsnprintf(const char *fmt, va_list args, t_buffer *buffer)
{
	while (*fmt != 0)
	{
		if (*fmt != '%')
		{
			ft_putchar(buffer, *fmt);
			fmt++;
		}
		else
		{
			phase_arg(args, fmt + 1, buffer);
			fmt += 2;
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_buffer	buffer;

	buffer.len = 0;
	buffer.ret = 0;
	va_start(args, fmt);
	ft_vsnprintf(fmt, args, &buffer);
	ft_fflush(&buffer);
	va_end(args);
	return (buffer.ret);
}
