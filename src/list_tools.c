/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/03 09:24:45 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/14 11:43:27 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

t_point		init_point(int x, int y, int z)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	ret.z = z;
	return (ret);
}

t_pt_lst	*new_pt(int x, int y, int z)
{
	t_pt_lst	*new;

	if (!(new = (t_pt_lst*)malloc(sizeof(t_pt_lst))))
		return (NULL);
	new->pt = init_point(x, y, z);
	new->next = NULL;
	return (new);
}

void		ad_pt(t_pt_lst **start, int x, int y, int z)
{
	t_pt_lst	*tmp;

	if (*start == NULL)
		*start = new_pt(x, y, z);
	else
	{
		tmp = *start;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new_pt(x, y, z);
	}
}
