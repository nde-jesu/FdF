/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_if.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:03:16 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:51 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstiter_if(t_list *lst, void (*f)(t_list *elem), void *data,
		int (*cmp)(void*, void*))
{
	if (lst == NULL || f == NULL)
		return ;
	while (lst)
	{
		if (cmp(lst->content, data) == 0)
			f(lst);
		lst = lst->next;
	}
}
