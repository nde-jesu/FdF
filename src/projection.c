/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/14 15:20:04 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/16 19:03:45 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "fdf.h"

static t_point	rotate_x(t_point pt, double alpha)
{
	int	previous_y;

	previous_y = pt.y;
	pt.y = previous_y * cos(alpha) + pt.z * sin(alpha);
	pt.z = -previous_y * sin(alpha) + pt.z * cos(alpha);
	return (pt);
}

static t_point	rotate_y(t_point pt, double beta)
{
	int	previous_x;

	previous_x = pt.x;
	pt.x = previous_x * cos(beta) + pt.z * sin(beta);
	pt.z = -previous_x * sin(beta) + pt.z * cos(beta);
	return (pt);
}

static t_point	rotate_z(t_point pt, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = pt.x;
	previous_y = pt.y;
	pt.x = previous_x * cos(gamma) - previous_y * sin(gamma);
	pt.y = previous_x * sin(gamma) + previous_y * cos(gamma);
	return (pt);
}

static t_point	iso(t_point pt)
{
	int	previous_x;
	int	previous_y;

	previous_x = pt.x;
	previous_y = pt.y;
	pt.x = (previous_x - previous_y) * cos(0.523599);
	pt.y = -pt.z + (previous_x + previous_y) * sin(0.523599);
	return (pt);
}

t_point			transform_pt(t_point pt, t_fdf *fdf)
{
	pt.color = get_fst_clr(fdf->z_min, fdf->z_max, pt.z);
	pt.x *= fdf->cam->zoom;
	pt.y *= fdf->cam->zoom;
	pt.z *= fdf->cam->zoom / fdf->cam->z_divisor;
	pt.x -= (fdf->x_max * fdf->cam->zoom) / 2;
	pt.y -= (fdf->y_max * fdf->cam->zoom) / 2;
	pt = rotate_x(pt, fdf->cam->alpha);
	pt = rotate_y(pt, fdf->cam->beta);
	pt = rotate_z(pt, fdf->cam->gamma);
	if (fdf->cam->proj == 0)
		pt = iso(pt);
	pt.x += (WIDTH - MENU_WIDTH) / 2 + fdf->cam->x_offset;
	pt.y += (HEIGHT - MENU_WIDTH + fdf->y_max * fdf->cam->zoom) / 2 + \
		fdf->cam->y_offset;
	return (pt);
}
