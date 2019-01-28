/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strndup.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:51:28 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/15 08:34:24 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strndup(const char *s1, size_t n)
{
	size_t	i;
	char	*ret;

	i = 0;
	if (!(ret = (char*)malloc(sizeof(char) * (n + 1))))
		return (NULL);
	while (s1[i] && i < n)
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
