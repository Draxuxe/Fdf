/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:34:57 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 18:44:58 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

int	get_index(int x, int y, int width)
{
	return (y * width + x);
}

t_vec2	vec_add(t_vec2 vec, int x, int y)
{
	return (v2f(vec.x + x, vec.y + y));
}

t_vec2	vec2_diff(t_vec2 a, t_vec2 b)
{
	return (v2f(abs(b.x - a.x), -abs(b.y - a.y)));
}

t_vec2	get_sign(t_vec2 a, t_vec2 b)
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
