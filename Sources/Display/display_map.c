/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:39:26 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 16:47:11 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	clear_image(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->window.height)
	{
		x = 0;
		while (x < fdf->window.width)
		{
			draw_pixel(&fdf->window, v2f(x, y), BLACK);
			x ++;
		}
		y ++;
	}
}

int	print_image(t_fdf *fdf)
{
	clear_image(fdf);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->window.mlx,
		fdf->window.win, fdf->window.img.mlx_img, 0, 0);
	return (0);
}

void	display_map(t_fdf fdf)
{
	init_controls(&fdf);
	mlx_loop(fdf.window.mlx);
	stop_render(&fdf.window);
	free_all(fdf.map);
}
