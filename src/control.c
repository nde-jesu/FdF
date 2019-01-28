/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 08:12:36 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/21 09:08:28 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "mlx_macro_keys.h"
#include "fdf.h"
#include <mlx.h>

int		close(void *param)
{
	free_all(param);
	exit(0);
	return (0);
}

int		user_command(int key, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	if (key == KEY_ESCAPE)
		close(param);
	if (key == KEY_PAD_ADD || key == KEY_PAD_SUB || key == KEY_MINUS \
			|| key == KEY_EQUAL)
		zoom(key, fdf);
	else if (key == KEY_LEFT || key == KEY_RIGHT || key == KEY_DOWN \
			|| key == KEY_UP)
		translation(key, fdf);
	else if (key == KEY_PAD_1 || key == KEY_PAD_2 || key == KEY_PAD_3\
			|| key == KEY_PAD_4 || key == KEY_PAD_6\
			|| key == KEY_PAD_7 || key == KEY_PAD_8 || key == KEY_PAD_9)
		rotation(key, fdf);
	else if (key == KEY_I || key == KEY_P)
		projection(key, fdf);
	else if (key == KEY_PAGE_UP || key == KEY_PAGE_DOWN)
		change_z(key, fdf);
	return (0);
}

void	get_ctrl(t_fdf *fdf)
{
	mlx_hook(fdf->mlx->win, 2, 0, user_command, fdf);
	mlx_hook(fdf->mlx->win, 17, 0, close, fdf);
	mlx_hook(fdf->mlx->win, 4, 0, press, fdf);
	mlx_hook(fdf->mlx->win, 5, 0, release, fdf);
	mlx_hook(fdf->mlx->win, 6, 0, move, fdf);
}

t_fdf	*new_img(t_fdf *fdf)
{
	mlx_destroy_image(fdf->mlx->ptr, fdf->mlx->img->ptr);
	fdf->mlx->img->ptr = mlx_new_image(fdf->mlx->ptr, WIDTH, HEIGHT);
	fdf->mlx->img->data = mlx_get_data_addr(fdf->mlx->img->ptr,
		&(fdf->mlx->img->bpp), &(fdf->mlx->img->size_l),
			&(fdf->mlx->img->endian));
	return (fdf);
}
