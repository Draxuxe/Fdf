/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotations.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 15:06:51 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/12 16:36:09 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	rotate_x(t_vec3 *vec, double alpha)
{
	int	previous_y;

	previous_y = vec->y;
	vec->y = previous_y * cos(alpha) + vec->z * sin(alpha);
	vec->z = -previous_y * sin(alpha) + vec->z * cos(alpha);
}

void	rotate_y(t_vec3 *vec, double beta)
{
	int	previous_x;

	previous_x = vec->x;
	vec->x = previous_x * cos(beta) + vec->z * sin(beta);
	vec->z = -previous_x * sin(beta) + vec->z * cos(beta);
}

void	rotate_z(t_vec3 *vec, double gamma)
{
	int	previous_x;
	int	previous_y;

	previous_x = vec->x;
	previous_y = vec->y;
	vec->x = previous_x * cos(gamma) - previous_y * sin(gamma);
	vec->y = previous_x * sin(gamma) + previous_y * cos(gamma);
}
