/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 14:27:54 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/16 10:00:08 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <mlx.h>
#include "fdf.h"

static t_fdf	*init_cam(t_fdf *fdf)
{
	fdf->cam->proj = 0;
	fdf->cam->x_offset = 0;
	fdf->cam->y_offset = 0;
	fdf->cam->z_divisor = 1;
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	return (fdf);
}

static t_fdf	*init_mouse(t_fdf *fdf)
{
	fdf->mouse.act_x = 0;
	fdf->mouse.act_y = 0;
	fdf->mouse.prev_y = 0;
	fdf->mouse.prev_x = 0;
	fdf->mouse.pressed = 0;
	return (fdf);
}

t_fdf			*init_fdf(void)
{
	t_fdf	*fdf;

	if (!(fdf = (t_fdf*)malloc(sizeof(t_fdf))))
		return (NULL);
	fdf->x_max = 0;
	fdf->y_max = 0;
	if (!(fdf->mlx = (t_mlx*)malloc(sizeof(t_mlx))))
		return (NULL);
	if (!(fdf->cam = (t_cam*)malloc(sizeof(t_cam))))
		return (NULL);
	if (!(fdf->mlx->img = (t_img*)malloc(sizeof(t_img))))
		return (NULL);
	fdf->mlx->ptr = mlx_init();
	if (!(fdf->mlx->win = mlx_new_window(fdf->mlx->ptr, WIDTH, HEIGHT, "FdF")))
		return (NULL);
	if (!(fdf->mlx->img->ptr = mlx_new_image(fdf->mlx->ptr, WIDTH, HEIGHT)))
		return (NULL);
	fdf->mlx->img->data = mlx_get_data_addr(fdf->mlx->img->ptr,
			&(fdf->mlx->img->bpp), &(fdf->mlx->img->size_l),
				&(fdf->mlx->img->endian));
	fdf = init_cam(fdf);
	fdf = init_mouse(fdf);
	return (fdf);
}
