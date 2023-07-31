/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_out_1.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang   < jinyang@student.42tokyo.>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 01:13:47 by jinyang           #+#    #+#             */
/*   Updated: 2022/07/24 01:16:17 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	ft_fflush(t_buffer *Buffer)
{
	write(1, Buffer->buffer, Buffer->len);
	Buffer->ret += Buffer->len;
}

void	ft_putchar(t_buffer *Buffer, char c)
{
	if (Buffer->len + 1 <= BUFFERSIZE)
	{
		Buffer->buffer[Buffer->len] = c;
		Buffer->len += 1;
	}
	else
	{
		ft_fflush(Buffer);
		Buffer->buffer[0] = c;
		Buffer->len = 1;
	}
}

void	ft_putstr(t_buffer *Buffer, char *str)
{
	if (str == NULL)
		ft_putstr(Buffer, "(null)");
	else
	{
		while (*str != 0)
		{
			ft_putchar(Buffer, *str);
			str++;
		}
	}
}
