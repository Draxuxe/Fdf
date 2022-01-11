/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:47:14 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/11 15:43:46 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

/*
static int	convert_rgba(int a, int r, int g, int b)
{
	return ((255 - a) << 24 | r << 16 | g << 8 | b);
}

static int	rgb(int r, int g, int b)
{
	return (convert_rgba(255, r, g, b));
}*/

static double	get_percent(int current, int start, int end)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

static double	get_light(int start, int end, double percentage)
{
	return (((int)(1 - percentage)) * start + percentage * end);
}

int	get_fade_color(t_vec2 current, t_vec2 start, t_vec2 end, t_vec2 delta)
{
	int		red;
	int		green;
	int		blue;
	double	percent;

	if (current.color == end.color)
		return (current.color);
	if (delta.x < delta.y)
		percent = get_percent(start.x, end.x, current.x);
	else
		percent = get_percent(start.y, end.y, current.y);
	red = get_light((start.color >> 16 & 0xFF),
			(end.color >> 16 & 0xFF), percent);
	green = get_light((start.color >> 8 & 0xFF),
			(end.color >> 8 & 0xFF), percent);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percent);
	return ((red << 16) | (green << 8) | blue);
}

static int	get_color(int z, t_map *map)
{
	double	percent;

	percent = (get_percent(z, map->z_min, map->z_max));
	if (percent < 0.2)
		return (COLOR_DISCO);
	else if (percent < 0.4)
		return (COLOR_RED);
	else if (percent < 0.6)
		return (COLOR_ORANGE);
	else if (percent < 0.8)
		return (COLOR_YELLOW);
	else
		return (COLOR_SAFRON);
}

int	get_point_color(t_point *point, t_fdf *fdf)
{
	if (point->color == -1)
		return (get_color(point->z, fdf->map));
	return (point->color);
}
