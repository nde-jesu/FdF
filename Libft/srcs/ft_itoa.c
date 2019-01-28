/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 09:34:40 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:13:11 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <limits.h>
#include "../includes/libft.h"

static int		ft_int_lenght(int n)
{
	int		i;

	i = 0;
	if (n < 0)
		++i;
	if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		++i;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char	*ret;
	int		negative;
	int		i;

	i = ft_int_lenght(n);
	negative = 0;
	if (n < 0)
	{
		if (n == INT_MIN)
			return (ft_strdup("-2147483648"));
		++negative;
		n *= -1;
	}
	if (!(ret = (char*)malloc(sizeof(char) * ((size_t)i + 1))))
		return (NULL);
	ret[i] = '\0';
	while (i > 0)
	{
		ret[i - 1] = n % 10 + '0';
		n /= 10;
		--i;
	}
	if (negative == 1)
		ret[0] = '-';
	return (ret);
}
