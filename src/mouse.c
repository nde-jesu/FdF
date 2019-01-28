/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:58:33 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/16 09:35:19 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "mlx_macro_keys.h"

int		press(int click, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	fdf = (t_fdf*)param;
	if (click == MOUSE_SCROLL_UP || click == MOUSE_SCROLL_DOWN)
		zoom(click, param);
	else if (click == MOUSE_LEFT_BUTTON)
		fdf->mouse.pressed = 1;
	return (0);
}

int		release(int click, int x, int y, void *param)
{
	t_fdf	*fdf;

	(void)x;
	(void)y;
	(void)click;
	fdf = (t_fdf*)param;
	fdf->mouse.pressed = 0;
	return (0);
}

int		move(int x, int y, void *param)
{
	t_fdf	*fdf;

	fdf = (t_fdf*)param;
	fdf->mouse.prev_x = fdf->mouse.act_x;
	fdf->mouse.prev_y = fdf->mouse.act_y;
	fdf->mouse.act_x = x;
	fdf->mouse.act_y = y;
	if (fdf->mouse.pressed)
	{
		fdf = new_img(fdf);
		fdf->cam->beta += (x - fdf->mouse.prev_x) * 0.002;
		fdf->cam->alpha += (y - fdf->mouse.prev_y) * 0.002;
		print_2d(fdf->start, fdf);
	}
	return (0);
}
