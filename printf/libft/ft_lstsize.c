/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jinyang <jinyang@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:25:26 by jinyang           #+#    #+#             */
/*   Updated: 2023/07/30 20:11:14 by jinyang          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int				count;
	struct s_list	*ptr;

	ptr = lst;
	if (ptr == NULL)
		return (0);
	count = 0;
	while (ptr->content != NULL)
	{
		count++;
		ptr = ptr->next;
	}
	return (count);
}
