/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 09:05:47 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/16 10:39:43 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <mlx.h>
#include "mlx_macro_keys.h"

void	zoom(int key, t_fdf *fdf)
{
	fdf = new_img(fdf);
	if (key == KEY_PAD_ADD || key == KEY_EQUAL || key == MOUSE_SCROLL_UP)
		++fdf->cam->zoom;
	else if (key == KEY_PAD_SUB || key == KEY_MINUS || key ==\
			MOUSE_SCROLL_DOWN)
		--fdf->cam->zoom;
	if (fdf->cam->zoom < 0)
		fdf->cam->zoom = 1;
	print_2d(fdf->start, fdf);
}

void	translation(int key, t_fdf *fdf)
{
	fdf = new_img(fdf);
	if (key == KEY_LEFT)
		fdf->cam->x_offset -= 10;
	if (key == KEY_RIGHT)
		fdf->cam->x_offset += 10;
	if (key == KEY_UP)
		fdf->cam->y_offset -= 10;
	if (key == KEY_DOWN)
		fdf->cam->y_offset += 10;
	print_2d(fdf->start, fdf);
}

void	rotation(int key, t_fdf *fdf)
{
	fdf = new_img(fdf);
	if (key == KEY_PAD_1)
		fdf->cam->gamma += 0.05;
	else if (key == KEY_PAD_7)
		fdf->cam->gamma += 0.05;
	else if (key == KEY_PAD_3)
		fdf->cam->gamma -= 0.05;
	else if (key == KEY_PAD_9)
		fdf->cam->gamma -= 0.05;
	else if (key == KEY_PAD_2)
		fdf->cam->alpha += 0.05;
	else if (key == KEY_PAD_8)
		fdf->cam->alpha -= 0.05;
	else if (key == KEY_PAD_6)
		fdf->cam->beta += 0.05;
	else if (key == KEY_PAD_4)
		fdf->cam->beta -= 0.05;
	print_2d(fdf->start, fdf);
}

void	projection(int key, t_fdf *fdf)
{
	fdf = new_img(fdf);
	fdf->cam->alpha = 0;
	fdf->cam->beta = 0;
	fdf->cam->gamma = 0;
	fdf->cam->x_offset = 0;
	fdf->cam->y_offset = 0;
	fdf->cam->z_divisor = 1;
	fdf->cam->zoom = ft_min(WIDTH / fdf->x_max / 2, HEIGHT / fdf->y_max / 2);
	if (key == KEY_I)
		fdf->cam->proj = 0;
	else if (key == KEY_P)
		fdf->cam->proj = 1;
	print_2d(fdf->start, fdf);
}

void	change_z(int key, t_fdf *fdf)
{
	fdf = new_img(fdf);
	if (key == KEY_PAGE_UP)
		fdf->cam->z_divisor -= 0.1;
	else if (key == KEY_PAGE_DOWN)
		fdf->cam->z_divisor += 0.1;
	if (fdf->cam->z_divisor < 0.1)
		fdf->cam->z_divisor = 0.1;
	else if (fdf->cam->z_divisor > 5)
		fdf->cam->z_divisor = 5;
	print_2d(fdf->start, fdf);
}
