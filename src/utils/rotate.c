/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:33:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 00:21:34 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	connect(t_list *first, t_list *second)
{
	if (!first || !second)
		return ;
	first->next = second;
	second->prev = first;
}

static void	rotate(t_list **stack_head)
{
	t_list	*null_guard;
	t_list	*cur_head;
	t_list	*cur_last;
	t_list	*new_head;

	if (!(*stack_head) || !((*stack_head)->next))
		return ;
	if (!(*stack_head)->content || !(*stack_head)->next->content)
		return ;
	cur_head = *stack_head;
	null_guard = cur_head->prev;
	cur_last = null_guard->prev;
	new_head = cur_head->next;
	*stack_head = new_head;
	connect(cur_head, null_guard);
	connect(null_guard, new_head);
	connect(cur_last, cur_head);
}

void	ra(t_list **stack_a)
{
	rotate(stack_a);
	ft_printf("ra\n");
}

void	rb(t_list **stack_b)
{
	rotate(stack_b);
	ft_printf("rb\n");
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
}
