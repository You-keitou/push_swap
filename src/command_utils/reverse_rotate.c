/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:42:02 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 04:30:36 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	reverse_rotate(t_list **stack_head)
{
	t_list	*cur_head;
	t_list	*cur_last;
	t_list	*new_last;
	t_list	*null_guard;

	if (!(*stack_head) || !((*stack_head)->next))
		return ;
	if (!(*stack_head)->content || !(*stack_head)->next->content)
		return ;
	cur_head = *stack_head;
	null_guard = cur_head->prev;
	cur_last = null_guard->prev;
	new_last = cur_last->prev;
	*stack_head = cur_last;
	connect(new_last, null_guard);
	connect(null_guard, cur_last);
	connect(cur_last, cur_head);
}

void	rra(t_list **stack_a)
{
	reverse_rotate(stack_a);
	ft_printf("rra\n");
}

void	rrb(t_list **stack_b)
{
	reverse_rotate(stack_b);
	ft_printf("rrb\n");
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_printf("rrr\n");
}
