/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:54:46 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 02:44:52 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

//output
int		ft_printf(const char *fmt, ...);

//init
bool	check_argv(int size, char **argv, int *array);
void	cord_compress(int *array, int size);
bool	is_sorted(int *array, int size);
void	init_stack(t_list **stack_a, t_list **stack_b, int *srray, int size);

//stack operation
void	connect(t_list *first, t_list *second);
void	sa(t_list **stack);
void	sb(t_list **stack);
void	ss(t_list **stack_a, t_list **stack_b);
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
void	ra(t_list **stack);
void	rb(t_list **stack);
void	rr(t_list **stack_a, t_list **stack_b);
void	rra(t_list **stack);
void	rrb(t_list **stack);
void	rrr(t_list **stack_a, t_list **stack_b);

//sort
void sort(t_list **stack_a, t_list **stack_b, int size);
#endif