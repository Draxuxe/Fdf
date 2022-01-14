/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:33:34 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 13:36:58 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

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

static int	get_color(int z, t_map *map)
{
	double	percent;

	percent = (get_percent(z, map->z_min, map->z_max));
	if (percent < 0.2)
		return (0xFFFFFF);
	else if (percent < 0.4)
		return (0xFFFFFF);
	else if (percent < 0.6)
		return (0xFFFFFF);
	else if (percent < 0.8)
		return (0xFFFFFF);
	else
		return (0xFFFFFF);
}

int	get_point_color(t_point *point, t_fdf *fdf)
{
	if (point->color == -1)
		return (get_color(point->z, fdf->map));
	return (point->color);
}
