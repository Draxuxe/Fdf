/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:41:00 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/14 10:44:50 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

double	degree_to_rad(int degree)
{
	double	rad;

	rad = degree * 3.14159265F / 180.0F;
	return (rad);
}

void	convert_vec3(t_map **map)
{
	t_point	**vec2;
	size_t	nb_vecs;
	size_t	size_map;

	size_map = (*map)->height * (*map)->width - 1;
	nb_vecs = vec_length((*map)->vectors) - 1;
	vec2 = (t_point **)malloc(sizeof(t_point *) * (size_map + 2));
	if (!vec2)
		exit (EXIT_FAILURE);
	vec2[size_map + 1] = NULL;
	(*map)->z_max = (*map)->vectors[nb_vecs]->z;
	(*map)->z_min = (*map)->z_max;
	while ((*map)->vectors[nb_vecs])
	{
		vec2[size_map] = (t_point *)malloc(sizeof(t_point));
		vec2[size_map]->z = (*map)->vectors[nb_vecs]->z;
		if ((*map)->z_max < (*map)->vectors[nb_vecs]->z)
			(*map)->z_max = (*map)->vectors[nb_vecs]->z;
		if ((*map)->z_min > (*map)->vectors[nb_vecs]->z)
			(*map)->z_min = (*map)->vectors[nb_vecs]->z;
		vec2[size_map]->color = (*map)->vectors[nb_vecs]->color;
		size_map --;
		nb_vecs --;
	}
	(*map)->coords = vec2;
}
