/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/15 09:11:56 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:14:17 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void	ft_lstrev(t_list **alst)
{
	t_list	*prev;
	t_list	*curr;
	t_list	*next;

	if (*alst == NULL)
		return ;
	prev = NULL;
	curr = NULL;
	curr = *alst;
	while (curr)
	{
		next = curr->next;
		curr->next = prev;
		prev = curr;
		curr = next;
	}
	*alst = prev;
}
