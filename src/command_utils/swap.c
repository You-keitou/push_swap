/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 01:13:50 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 12:57:41 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	swap(t_list **stack)
{
	t_list	*first_node;
	t_list	*second_node;
	int		*tmp;

	if (!*stack)
		return ;
	first_node = *stack;
	second_node = (*stack)->next;
	if (first_node == second_node || !second_node->content)
		return ;
	tmp = first_node->content;
	first_node->content = second_node->content;
	second_node->content = tmp;
}

void	sa(t_list **stack)
{
	swap(stack);
	ft_printf("sa\n");
}

void	sb(t_list **stack)
{
	swap(stack);
	ft_printf("sb\n");
}
