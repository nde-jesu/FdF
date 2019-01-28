/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:46:44 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/13 12:42:26 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j] && i + j < len)
			++j;
		if (needle[j] == '\0')
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
