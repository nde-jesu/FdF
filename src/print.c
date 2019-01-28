/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 14:29:07 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/16 18:56:01 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>

int		next_z(t_pt_lst **lst, t_fdf *fdf)
{
	t_pt_lst	*tmp;
	int			i;

	i = -1;
	tmp = *lst;
	while (++i < fdf->x_max && tmp->next)
		tmp = tmp->next;
	return (tmp->pt.z);
}

void	print_2d(t_pt_lst *ptr, t_fdf *fdf)
{
	int			x;
	int			y;
	int			z;

	y = -1;
	z = 0;
	while (++y < fdf->y_max)
	{
		x = -1;
		while (++x < fdf->x_max && ptr->next)
		{
			if (x != fdf->x_max - 1)
				print_line_img(transform_pt(init_point(x, y, ptr->pt.z), fdf),\
						transform_pt(init_point((x + 1), y, ptr->next->pt.z),\
							fdf), fdf);
			if (y != fdf->y_max - 1)
				print_line_img(transform_pt(init_point(x, y, ptr->pt.z), fdf),\
						transform_pt(init_point(x, (y + 1), next_z(&ptr, fdf)),\
							fdf), fdf);
			ptr = ptr->next;
		}
	}
	mlx_put_image_to_window(fdf->mlx->ptr, fdf->mlx->win, fdf->mlx->img->ptr,\
			MENU_WIDTH, 0);
}
