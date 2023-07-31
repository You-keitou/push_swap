/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 12:56:50 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, NULL);
	ft_lstclear(stack_b, NULL);
	free(stack_a);
	free(stack_b);
}

static void	error()
{
	ft_printf("Error\n");
	exit(1);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_list	**stack_a;
	t_list	**stack_b;

	array = (int *)malloc(sizeof(int) * (argc - 1));
	stack_a = (t_list **)malloc(sizeof(t_list *));
	stack_b = (t_list **)malloc(sizeof(t_list *));
	if (check_argv(argc - 1, argv, array))
	{
		free(array);
		error();
	}
	else
	{
		if (is_sorted(array, argc - 1))
			return (0);
		cord_compress(array, argc - 1);
		init_stack(stack_a, stack_b, array, argc - 1);
		sort(stack_a, stack_b, argc - 1);
		free(array);
		free_stack(stack_a, stack_b);
	}
	return (0);
}
