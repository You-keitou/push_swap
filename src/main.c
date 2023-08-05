/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:56:29 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/05 13:56:56 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include "stdio.h"

static void	free_stack(t_list **stack_a, t_list **stack_b)
{
	ft_lstclear(stack_a, NULL);
	ft_lstclear(stack_b, NULL);
	free(stack_a);
	free(stack_b);
}

static void	error(void)
{
	ft_printf("Error\n");
	exit(1);
}

static int	*is_valid_argv(int argc, char **argv, int *new_size)
{
	int	*array;

	array = check_argv(argc - 1, argv + 1, new_size);
	if (!array)
		return (NULL);
	if (is_duplicated(array, *new_size))
	{
		free(array);
		return (NULL);
	}
	return (array);
}

int	main(int argc, char **argv)
{
	t_list	**stack_a;
	t_list	**stack_b;
	int		*array;
	int		new_size;

	array = is_valid_argv(argc, argv, &new_size);
	if (array)
	{
		if (is_sorted(array, new_size))
		{
			free(array);
			return (0);
		}
		cord_compress(array, new_size);
		init_stack(&stack_a, &stack_b, array, new_size);
		if (ft_lstsize(*stack_a) == new_size)
			sort(stack_a, stack_b, new_size);
		free(array);
		free_stack(stack_a, stack_b);
	}
	else
		error();
	return (0);
}

// __attribute__((destructor)) void destructor(void)
// {
// 	int		status;
// 	char	buf[50];

// 	snprintf(buf, 50, "leaks %d &> leaksout", getpid());
// 	status = system(buf);
// 	if (status)
// 	{
// 		write(2, "leak!!!\n", 8);
// 		system("cat leaksout >/dev/stderr");
// 		exit(1);
// 	}
// }
