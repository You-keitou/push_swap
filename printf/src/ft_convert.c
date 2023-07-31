/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/01 00:22:41 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 00:22:41 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libftprintf.h"

static int	ft_abs(int num)
{
	if (num < 0)
		return (-num);
	else
		return (num);
}

void	itoa_ten(int num, t_buffer *Buffer)
{
	static char	*base;
	char		temp[sizeof(int) * 8];
	int			temp_index;
	int			base_digit;
	bool		isneg;

	base = "0123456789";
	temp[0] = base[0];
	isneg = num < 0;
	if (num == 0)
		temp_index = 1;
	else
		temp_index = 0;
	base_digit = 10;
	while (num != 0)
	{
		temp[temp_index++] = base[ft_abs(num % base_digit)];
		num /= base_digit;
	}
	if (isneg)
		temp[temp_index++] = '-';
	while (--temp_index >= 0)
		ft_putchar(Buffer, temp[temp_index]);
}

void	itoa_unsigned(int num, t_buffer *Buffer)
{
	static char		*base;
	char			temp[sizeof(int) * 8];
	int				temp_index;
	unsigned int	base_digit;

	base = "0123456789";
	temp[0] = base[0];
	if (num == 0)
		temp_index = 1;
	else
		temp_index = 0;
	base_digit = 10;
	while (num != 0)
	{
		temp[temp_index++] = base[ft_abs(num % base_digit)];
		num /= base_digit;
	}
	while (--temp_index >= 0)
		ft_putchar(Buffer, temp[temp_index]);
}

void	itoa_x(unsigned int num, char *base, t_buffer *Buffer)
{
	char			temp[sizeof(int) * 8];
	int				temp_index;
	unsigned int	base_digit;

	temp[0] = base[0];
	if (num == 0)
		temp_index = 1;
	else
		temp_index = 0;
	base_digit = ft_strlen(base);
	while (num != 0)
	{
		temp[temp_index++] = base[ft_abs(num % base_digit)];
		num /= base_digit;
	}
	while (--temp_index >= 0)
		ft_putchar(Buffer, temp[temp_index]);
}

void	convert_p(uintptr_t num, char *base, t_buffer *Buffer)
{
	char			temp[sizeof(int) * 8];
	int				temp_index;
	unsigned int	base_digit;

	temp[0] = base[0];
	if (num == 0)
		temp_index = 1;
	else
		temp_index = 0;
	base_digit = ft_strlen(base);
	while (num != 0)
	{
		temp[temp_index++] = base[ft_abs(num % base_digit)];
		num /= base_digit;
	}
	while (--temp_index >= 0)
		ft_putchar(Buffer, temp[temp_index]);
}
