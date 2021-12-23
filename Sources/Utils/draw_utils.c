/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:34:57 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/23 12:05:49 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

int	degree_to_rad(int degree)
{
	int	rad;

	rad = degree * 3.14159265F / 180.0F;
	return (rad);
}

t_vec2	vec_add(t_vec2 vec, int x, int y)
{
	vec.x += x;
	vec.y += y;
	return (vec);
}

t_vec2	get_sign(t_vec2 a, t_vec2 b)
{
	return (v2f(abs(b.x - a.x), -abs(b.y - a.y)));
}

t_vec2	vec2_diff(t_vec2 a, t_vec2 b)
{
	t_vec2	new;

	if (a.x < b.x)
		new.x = 1;
	else
		new.x = -1;
	if (a.y < b.y)
		new.y = 1;
	else
		new.y = -1;
	return (new);
}
