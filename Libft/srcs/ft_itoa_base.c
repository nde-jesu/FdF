/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 09:54:13 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 08:55:55 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

static int		int_len(int value, int base)
{
	int		i;

	i = 0;
	while (value /= base)
		++i;
	return (i);
}

static int		ft_abs(int value)
{
	if (value < 0)
		value = -value;
	return (value);
}

char			*ft_itoa_base(int value, int base)
{
	int			len;
	char		*ret;
	char		*tab;
	int			flag;

	if (base < 2 || base > 16)
		return (0);
	flag = 0;
	len = 0;
	tab = "0123456789ABCDEF";
	if (value < 0 && base == 10)
		flag = 1;
	len = int_len(value, base) + flag + 1;
	if (!(ret = (char*)malloc(sizeof(char) * ((size_t)len + 1))))
		return (NULL);
	ret[len] = '\0';
	if (flag == 1)
		ret[0] = '-';
	while (len > flag)
	{
		ret[len - 1] = tab[ft_abs(value % base)];
		--len;
		value /= base;
	}
	return (ret);
}
