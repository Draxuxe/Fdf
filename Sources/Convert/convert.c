/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rblondia <rblondia@student.42-lyon.fr>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 16:41:00 by rblondia          #+#    #+#             */
/*   Updated: 2021/12/16 17:49:09 by rblondia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	convert_vec3(t_map **map)
{
	t_point **vec2;
	size_t	nb_vecs;
	size_t	size_map;

	size_map = (*map)->height * (*map)->width - 1;
	nb_vecs = vec_length((*map)->vectors);
	vec2 = (t_point **)malloc(sizeof(t_point *) * (size_map + 2));
	if (!vec2)
			exit (EXIT_FAILURE);
	vec2[size_map + 1] = NULL;
	while ((*map)->vectors[nb_vecs])
	{
		vec2[size_map] = (t_point *)malloc(sizeof(t_point));
		vec2[size_map]->z = (*map)->vectors[nb_vecs]->z;
		vec2[size_map]->color = (*map)->vectors[nb_vecs]->color;
		size_map --;
		nb_vecs--;
	}
	(*map)->coords = vec2;
}