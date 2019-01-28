/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:59:16 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/08 17:34:22 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <unistd.h>

char	*ft_strchr(const char *s, int c)
{
	int		i;

	i = 0;
	if (!c)
	{
		while (s[i])
			++i;
		return ((char*)(s + i));
	}
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char*)(s + i));
		++i;
	}
	return (NULL);
}
