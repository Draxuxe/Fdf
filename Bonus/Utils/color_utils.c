/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 11:47:14 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 18:44:51 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

double	get_percent(int current, int start, int end)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	if (distance == 0)
		return (1.0);
	return (placement / distance);
}

double	get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
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
