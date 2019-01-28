/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 13:09:46 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/17 11:11:57 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"

void	color_menu(void *win, void *ptr)
{
	int		x;
	int		y;

	y = 0;
	while (y < HEIGHT)
	{
		x = 0;
		while (x < MENU_WIDTH)
		{
			mlx_pixel_put(ptr, win, x, y, 0x1E1E1E);
			++x;
		}
		++y;
	}
}

void	print_menu(t_fdf *fdf)
{
	void	*win;
	void	*ptr;

	win = fdf->mlx->win;
	ptr = fdf->mlx->ptr;
	color_menu(win, ptr);
	mlx_string_put(ptr, win, 10, 20, 0xEAEAEA, "FdF");
	mlx_string_put(ptr, win, 10, 60, 0xEAEAEA, "How to use :");
	mlx_string_put(ptr, win, 10, 100, 0xEAEAEA, "Zoom : + / -");
	mlx_string_put(ptr, win, 10, 120, 0xEAEAEA, "Move : Arrows");
	mlx_string_put(ptr, win, 10, 140, 0xEAEAEA, "Rotations :");
	mlx_string_put(ptr, win, 10, 160, 0xEAEAEA, "X : 2 / 8 ");
	mlx_string_put(ptr, win, 10, 180, 0xEAEAEA, "Y : 4 / 6 ");
	mlx_string_put(ptr, win, 10, 200, 0xEAEAEA, "Z : 3 / 7 ");
	mlx_string_put(ptr, win, 10, 220, 0xEAEAEA, "Iso : I / Parallel : P");
	mlx_string_put(ptr, win, 10, 240, 0xEAEAEA, "Change Z : Pg Up / Down");
	mlx_string_put(ptr, win, 10, 300, 0xEAEAEA, "ESC to quit");
	mlx_string_put(ptr, win, 10, 1180, 0xEAEAEA, "Created by :");
	mlx_string_put(ptr, win, 10, 1200, 0xEAEAEA, "Reda-Con");
	mlx_string_put(ptr, win, 10, 1220, 0xEAEAEA, "Nde-Jesu");
}
