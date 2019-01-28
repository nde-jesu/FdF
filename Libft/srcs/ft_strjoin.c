/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:54:30 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:19:47 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*ret;

	if (!s1 || !s2)
		return (NULL);
	i = 0;
	while (s1[i])
		++i;
	j = i;
	i = 0;
	while (s2[i])
		++i;
	j += i;
	if (!(ret = (char*)malloc(sizeof(char) * ((size_t)j + 1))))
		return (NULL);
	i = -1;
	while (s1[++i])
		ret[i] = s1[i];
	j = -1;
	while (s2[++j])
		ret[i++] = s2[j];
	ret[i] = '\0';
	return (ret);
}
