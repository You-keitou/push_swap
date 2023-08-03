/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/04 02:03:10 by jinyang           #+#    #+#             */
/*   Updated: 2023/08/04 06:34:12 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_split_char(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		free(split[i]);
	free(split);
}

static int	convert_argv(int size, char **argv, int *array)
{
	int		i;
	char	*tmp;
	char	*arg;

	i = -1;
	while (++i < size)
	{
		array[i] = ft_atoi(argv[i]);
		tmp = ft_itoa(array[i]);
		if (!tmp)
			return (i);
		if (tmp[0] == '0')
			arg = argv[i] + (argv[i][0] == '+') + (argv[i][0] == '-');
		else
			arg = argv[i] + (argv[i][0] == '+');
		if (ft_strncmp(tmp, arg, ft_strlen(arg)))
		{
			free(tmp);
			return (i);
		}
		free(tmp);
	}
	return (size);
}

static int	*check_case_one(char **argv, int *new_size)
{
	char	**new_argv;
	char	**tmp;
	int		*array;
	int		size;

	new_argv = ft_split(*argv, ' ');
	if (!new_argv)
		return (NULL);
	size = 0;
	tmp = new_argv;
	while (*tmp++)
		size++;
	array = (int *)malloc(sizeof(int) * size);
	*new_size = size;
	if (convert_argv(size, new_argv, array) != size)
	{
		free_split_char(new_argv);
		free(array);
		return (NULL);
	}
	else
	{
		free_split_char(new_argv);
		return (array);
	}
}

int	*check_argv(int size, char **argv, int *new_size)
{
	int		*array;

	if (size == 1)
		return (check_case_one(argv, new_size));
	else
	{
		array = (int *)malloc(sizeof(int) * size);
		*new_size = size;
		if (convert_argv(size, argv, array) != size)
		{
			free(array);
			return (NULL);
		}
		else
			return (array);
	}
}

bool	is_duplicated(int *array, int size)
{
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = i;
		while (++j < size)
		{
			if (array[i] == array[j])
				return (true);
		}
	}
	return (false);
}
