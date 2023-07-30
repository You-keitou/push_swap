/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:23:05 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/30 22:00:47 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!new | !lst)
		return ;
	if (*lst == NULL)
		*lst = new;
	else
	{
		ft_lstinsert(new, (*lst)->prev, *lst);
		*lst = new;
	}
}
