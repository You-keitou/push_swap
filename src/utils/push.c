/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:37:28 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/01 02:47:22 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list	*cur_head;
	t_list	*cur_tail;

	if (!src || !dest)
		return ;
	if (*src && (*src)->content)
	{
		cur_head = (*src)->next;
		cur_tail = (*src)->prev;
		ft_lstadd_front(dest, *src);
		*src = cur_head;
		if (cur_head != cur_tail)
			connect(cur_tail, cur_head);
		else
		{
			(*src)->next = *src;
			(*src)->prev = *src;
		}
	}
}

void	pa(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_b->head, stack_a->head);
	stack_a->size++;
	stack_b->size--;
	ft_printf("pa\n");
}

void	pb(t_stack *stack_a, t_stack *stack_b)
{
	push(stack_a->head, stack_b->head);
	stack_a->size--;
	stack_b->size++;
	ft_printf("pb\n");
}
