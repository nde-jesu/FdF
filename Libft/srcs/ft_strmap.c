/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 12:59:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 08:48:48 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	unsigned long	i;
	char			*ret;

	i = 0;
	if (!s || f == NULL)
		return (NULL);
	while (s[i])
		++i;
	if (!(ret = (char*)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	i = 0;
	while (s[i])
	{
		ret[i] = f(s[i]);
		++i;
	}
	ret[i] = '\0';
	return (ret);
}
