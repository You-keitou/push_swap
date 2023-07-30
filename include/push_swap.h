/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:54:46 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 00:58:33 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

int		ft_printf(const char *fmt, ...);
bool	check_argv(int size, char **argv, int *array);
void	cord_compress(int *array, int size);
bool	is_sorted(int *array, int size);
void init_stack(t_list **stack_a, t_list **stack_b, int *srray, int size);
void push_swap(int *array, int size);
#endif