/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 15:29:57 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:32 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstdelone(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*to_del;

	if (*alst == NULL | del == NULL)
		return ;
	to_del = NULL;
	to_del = *alst;
	del(to_del->content, to_del->content_size);
	free(to_del);
	*alst = NULL;
}
