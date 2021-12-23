/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:39:26 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/23 13:50:34 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static int	rotate_infinity(void *f)
{
	t_fdf	*fdf;

	fdf = (t_fdf *) f;
	//fdf->camera->gamma += 0.05;
	print_image(fdf);
	//usleep(10000);
	return (0);
}

void	display_map(t_fdf fdf)
{
	fdf.window.title = "FDF";
	fdf.window.width = 1920;
	fdf.window.height = 1080;
	fdf.camera = NULL;
	fdf.projection = 'I';
	fdf.window.mlx = mlx_init();
	fdf.window.win = mlx_new_window(fdf.window.mlx, fdf.window.width,
			fdf.window.height, fdf.window.title);
	mlx_loop_hook(fdf.window.mlx, &rotate_infinity, &fdf);
	mlx_loop(fdf.window.mlx);
	free_all(fdf.map);
}
