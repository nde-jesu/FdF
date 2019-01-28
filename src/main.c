/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:50:03 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/23 14:30:28 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "libft.h"
#include <mlx.h>
#include <fcntl.h>
#include <stdlib.h>

int		error(int cases)
{
	if (cases == 1)
		ft_putendl_fd("usage : ./fdf <filename>", 2);
	else if (cases == 2)
		ft_putendl_fd("error", 2);
	else if (cases == 3)
		ft_putendl_fd("map error", 2);
	exit (1);
	return (1);
}

int		main(int ac, char **av)
{
	int			fd;
	t_fdf		*fdf;

	if (ac != 2)
		return (error(1));
	if ((fd = open(av[1], O_RDONLY)) < 0)
		return (error(2));
	if (!(fdf = init_fdf()))
		return (error(2));
	if (!(fdf->start = give_pos(fd, fdf)))
		return (error(3));
	fdf->cam->zoom = ft_min(WIDTH / fdf->x_max / 2, HEIGHT / fdf->y_max / 2);
	print_menu(fdf);
	print_2d(fdf->start, fdf);
	get_ctrl(fdf);
	mlx_loop(fdf->mlx->ptr);
	return (0);
}
