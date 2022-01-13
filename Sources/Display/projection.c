/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:42:27 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 15:46:32 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static t_vec2	isometric_projection(t_vec3 vec)
{
	return (v2f((vec.x - vec.y) * cos(0.523599),
			-vec.z + (vec.x + vec.y) * sin(0.523599)));
}

static t_vec2	parallel_projection(t_vec3 vec, int angle)
{
	return (v2f(vec.x + cos(degree_to_rad(angle)) * vec.z,
			vec.y + sin(degree_to_rad(angle)) * vec.z));
}

t_vec3	new_point(int x, int y, t_map *map)
{
	t_vec3	point;
	int		i;

	i = get_index(x, y, map->width);
	point.x = x;
	point.y = y;
	point.z = map->coords[i]->z;
	return (point);
}

t_vec2	projection(t_vec3 point, t_fdf fdf)
{
	t_vec2	vector;

	point.x *= fdf.camera->zoom;
	point.y *= fdf.camera->zoom;
	point.z *= fdf.camera->zoom / fdf.camera->z_divider;
	point.x -= (fdf.map->width * fdf.camera->zoom) / 2;
	point.y -= (fdf.map->height * fdf.camera->zoom) / 2;
	rotate_x(&point, fdf.camera->alpha);
	rotate_y(&point, fdf.camera->beta);
	rotate_z(&point, fdf.camera->gamma);
	if (fdf.projection == 'I')
		vector = isometric_projection(point);
	else
		vector = parallel_projection(point, 30);
	vector.x += fdf.window.width / 2 + fdf.camera->x_offset;
	vector.y += (fdf.window.height + fdf.map->height * fdf.camera->zoom)
		/ 2 + fdf.camera->y_offset;
	return (vector);
}
