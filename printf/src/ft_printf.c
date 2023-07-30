/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 03:03:54 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/24 01:07:21 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include "libft.h"

static void	phase_arg(va_list arg, const char *fmt, t_buffer *Buffer)
{
	if (*fmt == 'c')
		ft_putchar(Buffer, va_arg(arg, int));
	else if (*fmt == 's')
		ft_putstr(Buffer, va_arg(arg, char *));
	else if (*fmt == 'p')
	{
		ft_putstr(Buffer, "0x");
		convert_p(va_arg(arg, uintptr_t), "0123456789abcdef", Buffer);
	}
	else if (*fmt == 'd' || *fmt == 'i')
		itoa_ten(va_arg(arg, int), Buffer);
	else if (*fmt == 'u')
		itoa_unsigned(va_arg(arg, int), Buffer);
	else if (*fmt == 'x')
		itoa_x(va_arg(arg, int), "0123456789abcdef", Buffer);
	else if (*fmt == 'X')
		itoa_x(va_arg(arg, int), "0123456789ABCDEF", Buffer);
	else if (*fmt == '%')
		ft_putchar(Buffer, '%');
}

void	ft_vsnprintf(const char *fmt, va_list args, t_buffer *Buffer)
{
	while (*fmt != 0)
	{
		if (*fmt != '%')
		{
			ft_putchar(Buffer, *fmt);
			fmt ++;
		}
		else
		{
			phase_arg(args, fmt + 1, Buffer);
			fmt += 2;
		}
	}
}

int	ft_printf(const char *fmt, ...)
{
	va_list		args;
	t_buffer	Buffer;

	Buffer.len = 0;
	Buffer.ret = 0;
	va_start(args, fmt);
	ft_vsnprintf(fmt, args, &Buffer);
	ft_fflush(&Buffer);
	va_end(args);
	return (Buffer.ret);
}
