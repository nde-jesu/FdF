/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:58:42 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:26 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list		*tmp;
	t_list		*to_del;

	if (*alst == NULL || del == NULL)
		return ;
	to_del = NULL;
	tmp = NULL;
	to_del = *alst;
	tmp = to_del;
	while (tmp)
	{
		tmp = to_del->next;
		del(to_del->content, to_del->content_size);
		free(to_del);
		to_del = tmp;
	}
	*alst = NULL;
}
