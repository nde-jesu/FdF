/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:41:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/11/13 14:19:56 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

char	*ft_strstr(const char *haystack, const char *needle)
{
	int		i;
	int		j;

	i = 0;
	if (!(haystack[i]) && !(needle[i]))
		return ((char*)(haystack + i));
	while (haystack[i])
	{
		j = 0;
		while (needle[j] == haystack[i + j] && needle[j])
			++j;
		if (needle[j] == '\0')
			return ((char*)(haystack + i));
		++i;
	}
	return (NULL);
}
