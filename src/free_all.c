/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:13:07 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/15 17:16:29 by reda-con         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void	free_all(t_fdf *fdf)
{
	t_pt_lst	*tmp;

	tmp = NULL;
	free(fdf->mlx->ptr);
	free(fdf->mlx->win);
	free(fdf->mlx->img->ptr);
	free(fdf->mlx->img->data);
	free(fdf->mlx->img);
	free(fdf->mlx);
	free(fdf->cam);
	while (fdf->start)
	{
		tmp = fdf->start->next;
		free(fdf->start);
		fdf->start = tmp;
	}
}
