/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectors.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 12:25:31 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 13:40:41 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

t_vec2	v2f(int x, int y)
{
	t_vec2	v;

	v.x = x;
	v.y = y;
	return (v);
}

static t_vec3	*create_vector(int x, int y, int z, int color)
{
	t_vec3	*newvec;

	(void) color;
	newvec = (t_vec3 *)malloc(sizeof(t_vec3));
	if (!newvec)
		return (NULL);
	newvec->x = x;
	newvec->y = y;
	newvec->z = z;
	newvec->color = 0xFFFFFF;
	return (newvec);
}

void	verify_vec(t_vec3 *v)
{
	if (!v)
	{
		errno = 11;
		perror("Map isn't valid");
		exit (EXIT_FAILURE);
	}
}

t_vec3	*get_z_vec(int x, int y, char *s)
{
	t_vec3	*v;
	char	**split;
	int		z;

	if (!s || ft_strlen(s) <= 0)
		return (NULL);
	split = ft_split(s, ',');
	if (!split)
		return (NULL);
	z = ft_atoi(split[0]);
	if ((z == -1 && split[0][0] != '-'))
	{
		free_split(split);
		return (NULL);
	}
	v = create_vector(x, y, z, ft_atoi_base(split[1]));
	free_split(split);
	if (!v)
		return (NULL);
	return (v);
}
