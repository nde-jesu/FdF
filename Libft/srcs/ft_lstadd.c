/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 08:12:06 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:20 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"
#include <stdlib.h>

void	ft_lstadd(t_list **alst, t_list *news)
{
	t_list	*tmp;

	if (news == NULL)
		return ;
	tmp = *alst;
	news->next = tmp;
	*alst = news;
}
