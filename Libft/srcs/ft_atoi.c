/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:02:17 by nde-jesu          #+#    #+#             */
/*   Updated: 2018/12/06 09:21:12 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *str)
{
	int		res;
	int		i;
	int		minus;

	res = 0;
	i = 0;
	minus = 1;
	while (str[i] == ' ' || str[i] == '\r' || str[i] == '\n' ||
		str[i] == '\v' || str[i] == '\f' || str[i] == '\t')
		++i;
	if (str[i] == '-')
		minus = -1;
	if (str[i] == '-' || str[i] == '+')
		++i;
	while (str[i])
	{
		if (str[i] >= '0' && str[i] <= '9')
			res = res * 10 + str[i] - 48;
		if (str[i] < '0' || str[i] > '9')
			return ((int)(res * minus));
		++i;
	}
	return ((int)(res * minus));
}
