/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 15:13:08 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/13 11:40:14 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	void	*ret;

	i = 0;
	if (!(ret = malloc(size)))
		return (NULL);
	while (i < size)
	{
		*(unsigned char*)(ret + i) = 0;
		++i;
	}
	return (ret);
}
