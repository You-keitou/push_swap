/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 22:02:49 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 02:48:25 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

bool	is_sorted(int *array, int size)
{
	int index;

	index = -1;
	while(++index < size - 1)
	{
		if (array[index] > array[index + 1])
			return (false);
	}
	return (true);
}

bool	check_argv(int size, char **argv, int *array)
{
	int		i;
	char	*tmp;
	char	*arg;

	i = -1;
	if (size == 0)
		return (true);
	while (++i < size)
	{
		array[i] = ft_atoi(argv[i + 1]);
		tmp = ft_itoa(array[i]);
		if (argv[i + 1][0] == '+')
			arg = argv[i + 1] + 1;
		else
			arg = argv[i + 1];
		if (ft_strncmp(tmp, arg, ft_strlen(tmp)))
		{
			free(tmp);
			return (true);
		}
		free(tmp);
	}
	return (false);
}

static int	*bubble_sort(int *array, int size)
{
	int	*sorted_array;
	int	i;
	int	j;

	sorted_array = (int *)malloc(sizeof(int) * size);
	if (sorted_array)
	{
		i = -1;
		while(++i < size)
			sorted_array[i] = array[i];
		i = -1;
		while (++i < size - 1)
		{
			j = i - 1;
			while (++j < size - 1)
			{
				if (sorted_array[j] > sorted_array[j + 1])
					ft_swap(sorted_array + j, sorted_array + j + 1);
			}
		}
	}
	return (sorted_array);
}

void	cord_compress(int *array, int size)
{
	int	*sorted;
	int	i;
	int	j;

	sorted = bubble_sort(array, size);
	if (!sorted)
		return;
	i = -1;
	while(++i < size)
	{
		j = -1;
		while (++j < size)
		{
			if (array[i] == sorted[j])
			{
				array[i] = j;
				break;
			}
		}
	}
	free(sorted);
}

void	init_stack(t_list **stack_a, t_list **stack_b, int *array, int size)
{
	int	i;

	*stack_a = NULL;
	*stack_b = NULL;
	i = -1;
	while(++i < size)
		ft_lstadd_back(stack_a, ft_lstnew(array + i));
	ft_lstadd_back(stack_a, ft_lstnew(NULL));
	ft_lstadd_back(stack_b, ft_lstnew(NULL));
}
