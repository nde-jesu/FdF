/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:03:26 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 08:48:23 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strdup(const char *s1)
{
	char			*ret;
	unsigned long	i;

	i = 0;
	while (s1[i])
		++i;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
