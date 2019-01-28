/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:10:20 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 08:57:46 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ct_words(char const *s, char c)
{
	size_t		i;
	size_t		j;

	i = 0;
	j = 0;
	while (s[i] == c)
		++i;
	if (s[i] != '\0')
		++j;
	while (s[i])
	{
		if (s[i] == c)
		{
			while (s[i] == c)
				++i;
			if (s[i] != '\0')
				++j;
		}
		if (s[i])
			++i;
	}
	return (j);
}

static size_t	ct_char(char const *s, int i, char c)
{
	size_t		j;

	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (j);
		++i;
		++j;
	}
	return (j);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	int		i;
	size_t	j;
	int		k;

	if (!s)
		return (NULL);
	if (!(ret = (char**)malloc(sizeof(char*) * (ct_words(s, c) + 1))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < ct_words(s, c))
	{
		k = 0;
		while (s[i] == c)
			++i;
		if (!(ret[j] = (char*)malloc(sizeof(char) * (ct_char(s, i, c) + 1))))
			return (NULL);
		while (s[i] != c && s[i])
			ret[j][k++] = s[i++];
		ret[j++][k] = '\0';
	}
	ret[j] = 0;
	return (ret);
}
