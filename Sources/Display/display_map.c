/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:39:26 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/10 17:59:31 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static int	rotate_infinity(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) f;
	fdf->camera->gamma += 0.05;
	usleep(1000);
	return (0);
}

void	display_map(t_fdf fdf)
{
	mlx_loop_hook(fdf.window.mlx, &rotate_infinity, &fdf);
	mlx_loop_hook(fdf.window.mlx, &print_image, &fdf);
	mlx_loop(fdf.window.mlx);
	stop_render(&fdf.window);
	free_all(fdf.map);
}
