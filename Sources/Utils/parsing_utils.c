/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 11:49:06 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 16:40:29 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

size_t	vec_length(t_vec3 **a)
{
	size_t	i;

	if (!a)
		return (0);
	i = 0;
	while (a[i])
		i ++;
	return (i);
}

size_t	split_size(char **s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i ++;
	return (i);
}

t_vec3	**join_vectors(t_vec3 **vectors, t_vec3 **c, t_map *map)
{
	t_vec3	**joined;
	size_t	i;
	size_t	j;

	if (!vectors || !c)
		return (NULL);
	i = -1;
	j = vec_length(vectors);
	joined = (t_vec3 **)malloc(sizeof(t_vec3) * (j + vec_length(c) + 1));
	if (!joined)
		return (NULL);
	while (vectors[++i])
		joined[i] = vectors[i];
	i = -1;
	while (c[++i])
		joined[i + j] = c[i];
	joined[i + j] = 0;
	if (map->width < (int) i)
		map->width = i;
	free(vectors);
	free(c);
	return (joined);
}
