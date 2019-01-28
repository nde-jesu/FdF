/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: reda-con <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 17:17:58 by reda-con          #+#    #+#             */
/*   Updated: 2019/01/17 10:46:05 by nde-jesu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(int start, int end, int current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_fst_clr(int min, int max, int act)
{
	double	prct;

	prct = percent(min, max, act);
	if (prct < 0.2)
		return (COLOR_GAMERS_BLUE);
	else if (prct < 0.4)
		return (COLOR_ZINZOLIN);
	else if (prct < 0.6)
		return (COLOR_CHARTREUSE);
	else if (prct < 0.8)
		return (COLOR_STOMACH_OF_HIND);
	else
		return (COLOR_THIGH_OF_NYMPH);
}

int		get_light(int start, int end, double prct)
{
	return ((int)((1 - prct) * start + prct * end));
}

int		get_clr(t_point cur, t_point a, t_point b, t_point delta)
{
	int		green;
	int		blue;
	int		red;
	double	prct;

	if (a.color == b.color)
		return (a.color);
	if (delta.x > delta.y)
		prct = percent(a.x, b.x, cur.x);
	else
		prct = percent(a.y, b.y, cur.y);
	red = get_light((a.color >> 16) & 0xFF, (b.color >> 16) & 0xFF, prct);
	green = get_light((a.color >> 8) & 0xFF, (b.color >> 8) & 0xFF, prct);
	blue = get_light(a.color & 0xFF, b.color & 0xFF, prct);
	return ((red << 16) | (green << 8) | blue);
}
