/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 23:07:15 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/31 00:42:47 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*tmp;
	t_list	*next_node;

	if (lst && *lst)
	{
		tmp = *lst;
		while (tmp->content)
		{
			next_node = tmp->next;
			if (del != NULL)
				del(tmp->content);
			free(tmp);
			tmp = next_node;
		}
		free(tmp);
		*lst = NULL;
	}
}
