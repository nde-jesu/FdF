/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nde-jesu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/13 12:44:48 by nde-jesu          #+#    #+#             */
/*   Updated: 2019/01/23 14:08:02 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "fdf.h"
#include <stdlib.h>

int			ft_isok(char c)
{
	return (ft_isdigit(c) || c == ' ' || c == '+' || c == '-');
}

void		get_m_z(int z, t_fdf *fdf)
{
	if (fdf->z_max < z)
		fdf->z_max = z;
	if (fdf->z_min > z)
		fdf->z_min = z;
}

int			norme(char *line, t_fdf *fdf)
{
	int		i;
	int		x;

	i = 0;
	x = 0;
	while (line[i])
	{
		if (line[i] != ' ')
		{
			ad_pt(&fdf->start, x, fdf->y_max, ft_atoi(line + i));
			get_m_z(ft_atoi(line + i), fdf);
			++x;
			while (line[i] != ' ' && line[i])
			{
				if (!(ft_isok(line[i])))
					return (-1);
				++i;
			}
		}
		if (line[i])
			++i;
	}
	free(line);
	return (x);
}

t_pt_lst	*give_pos(int fd, t_fdf *fdf)
{
	char		*line;
	int			x_max;
	int			error;
	int			x;

	x_max = 0;
	fdf->start = NULL;
	while ((error = get_next_line(fd, &line)) == 1)
	{
		if ((x = norme(line, fdf)) == -1)
			return (NULL);
		if (fdf->y_max == 0)
			x_max = x;
		else if (x != x_max)
			return (NULL);
		++fdf->y_max;
	}
	if (!(line) || error == -1)
		return (NULL);
	fdf->x_max = x_max;
	return (fdf->start);
}
