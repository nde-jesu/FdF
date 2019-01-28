/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 11:49:31 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/13 13:01:14 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tmp;

	i = ft_strlen(dst);
	tmp = i;
	j = 0;
	if (size == 0)
		return (ft_strlen(src));
	while (i < size - 1 && src[j])
	{
		dst[i] = src[j];
		++j;
		++i;
	}
	dst[i] = '\0';
	if (tmp < size)
		return (tmp + ft_strlen(src));
	return (size + ft_strlen(src));
}
