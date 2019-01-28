/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstfind.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 08:59:09 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:38 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

t_list		*ft_lstfind(t_list *lst, void *data, int (*cmp)(void*, void*))
{
	if (lst == NULL)
		return (NULL);
	while (lst)
	{
		if (cmp(lst->content, data) == 0)
			return (lst);
		lst = lst->next;
	}
	return (NULL);
}
