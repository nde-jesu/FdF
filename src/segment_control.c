/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   segment_control.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 07:51:24 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/16 19:02:29 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"

void	put_pixel_img(t_fdf *fdf, int x, int y, int color)
{
	int		i;

	if (x > 0 && x < WIDTH && y > 0 && y < HEIGHT)
	{
		i = (x * fdf->mlx->img->bpp / 8) + (y * fdf->mlx->img->size_l);
		fdf->mlx->img->data[i] = color;
		fdf->mlx->img->data[++i] = color >> 8;
		fdf->mlx->img->data[++i] = color >> 16;
	}
}

void	print_line_img(t_point a, t_point b, t_fdf *fdf)
{
	t_point		delta;
	t_point		sign;
	t_point		cur;
	int			tab[2];

	delta.x = ft_abs(b.x - a.x);
	delta.y = ft_abs(b.y - a.y);
	sign.x = a.x < b.x ? 1 : -1;
	sign.y = a.y < b.y ? 1 : -1;
	tab[0] = delta.x - delta.y;
	cur = a;
	while (cur.x != b.x || cur.y != b.y)
	{
		put_pixel_img(fdf, cur.x, cur.y, get_clr(cur, a, b, delta));
		if ((tab[1] = tab[0] * 2) > -delta.y)
		{
			tab[0] -= delta.y;
			cur.x += sign.x;
		}
		if (tab[1] < delta.x)
		{
			tab[0] += delta.x;
			cur.y += sign.y;
		}
	}
}
