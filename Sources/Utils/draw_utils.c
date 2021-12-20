/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 11:34:57 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/20 15:00:36 by lfilloux         ###   ########.fr       */
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

t_vec2	get_sign(t_vec2 a, t_vec2 b)
{
	
}

t_vec2	vec2_diff(t_vec2 a, t_vec2 b)
{
	
}
