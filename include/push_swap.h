/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:54:46 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 04:05:14 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"

typedef struct s_stack
{
	t_list	**head;
	int		size;
	int		cheapest;
	int		target;
	int		target_tmp;
}			t_stack;

// output
int			ft_printf(const char *fmt, ...);

// init
bool		check_argv(int size, char **argv, int *array);
void		cord_compress(int *array, int size);
bool		is_sorted(int *array, int size);
void		init_stack(t_list **stack_a, t_list **stack_b, int *srray,
				int size);
int			*bubble_sort(int *array, int size);

// stack operation
void		connect(t_list *first, t_list *second);
void		sa(t_list **stack);
void		sb(t_list **stack);
void		ss(t_list **stack_a, t_list **stack_b);
void		pa(t_stack *stack_a, t_stack *stack_b);
void		pb(t_stack *stack_a, t_stack *stack_b);
void		ra(t_list **stack);
void		rb(t_list **stack);
void		rr(t_list **stack_a, t_list **stack_b);
void		rra(t_list **stack);
void		rrb(t_list **stack);
void		rrr(t_list **stack_a, t_list **stack_b);

// sort
void		sort(t_list **head_a, t_list **head_b, int size);
void		sort_three(t_list **stack_a);
void		sort_complex(t_stack *stack_a, t_stack *stack_b);

// algorithm
int			find_nth_node(int num, t_list *stack);
bool		is_min_of_stack(int num, t_list *stack);
int			find_biggest_node(t_list *stack, int num);
void		insert(t_stack *stack_a, t_stack *stack_b);
#endif