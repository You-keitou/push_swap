/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstinsert.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 20:18:30 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/30 21:04:34 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstinsert(t_list *new, t_list *prev, t_list *next)
{
	if (!new | !prev | !next)
		return ;
	prev->next = new;
	new->prev = prev;
	new->next = next;
	next->prev = new;
}
