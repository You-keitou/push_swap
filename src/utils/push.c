/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_push.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:37:28 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 01:40:51 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	push(t_list **src, t_list **dest)
{
	t_list *cur_head;
	t_list *cur_tail;

	if (!src || !dest)
		return;
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

void	pa(t_list **stack_a, t_list **stack_b)
{
	push(stack_b, stack_a);
}

void	pb(t_list **stack_a, t_list **stack_b)
{
	push(stack_a, stack_b);
}
