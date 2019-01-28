/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 17:36:02 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 18:10:29 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;

	i = 0;
	while (s[i])
		++i;
	while (i > 0)
	{
		if ((const char)c == s[i])
			return ((char*)(s + i));
		--i;
	}
	if ((const char)c == s[i])
		return ((char*)s);
	return (NULL);
}
