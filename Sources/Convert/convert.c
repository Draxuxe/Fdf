/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:41:00 by rblondia          #+#    #+#             */
/*   Updated: 2022/01/19 13:10:48 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	convert_vec3(t_map **map)
{
	t_point	**vec2;
	size_t	size_map;
	size_t	i;

	i = 0;
	size_map = (*map)->height * (*map)->width;
	vec2 = malloc(sizeof(t_point *) * (size_map + 1));
	if (!vec2)
		exit (EXIT_FAILURE);
	while (i < size_map)
	{
		vec2[i] = malloc(sizeof(t_point));
		if (!vec2[i])
			exit (EXIT_FAILURE);
		vec2[i]->z = (*map)->vectors[i]->z;
		if ((*map)->z_max < (*map)->vectors[i]->z)
			(*map)->z_max = (*map)->vectors[i]->z;
		if ((*map)->z_min > (*map)->vectors[i]->z)
			(*map)->z_min = (*map)->vectors[i]->z;
		vec2[i]->color = (*map)->vectors[i]->color;
		i ++;
	}
	vec2[i] = NULL;
	(*map)->coords = vec2;
}
