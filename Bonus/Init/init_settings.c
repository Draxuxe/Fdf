/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_settings.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 10:44:08 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 10:37:50 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

static void	init_img(t_window *window)
{
	window->img.mlx_img = mlx_new_image(window->mlx,
			window->width, window->height);
	window->img.addr = mlx_get_data_addr(window->img.mlx_img, &window->img.bpp,
			&window->img.line_len, &window->img.endian);
}

static t_camera	*init_camera(t_fdf fdf)
{
	t_camera	*camera;
	int			a;
	int			b;

	camera = (t_camera *)malloc(sizeof(t_camera));
	if (!camera)
		exit(EXIT_FAILURE);
	a = fdf.window.width / fdf.map->width / 2;
	b = fdf.window.height / fdf.map->height / 2;
	if (a < b)
		camera->zoom = a;
	else
		camera->zoom = b;
	camera->alpha = 0;
	camera->beta = 0;
	camera->gamma = 0;
	camera->x_offset = 0;
	camera->y_offset = -50;
	camera->z_divider = 1;
	return (camera);
}

static	void	init_conf(t_fdf *fdf)
{
	fdf->projection = 'I';
}

static void	init_window(t_fdf *fdf)
{
	fdf->window.title = "FDF";
	fdf->window.width = 1920;
	fdf->window.height = 1080;
	fdf->window.mlx = mlx_init();
	fdf->window.win = mlx_new_window(fdf->window.mlx, fdf->window.width,
			fdf->window.height, fdf->window.title);
}

void	init_settings_bonus(t_fdf *fdf)
{
	init_conf(fdf);
	init_window(fdf);
	fdf->camera = init_camera(*fdf);
	init_img(&fdf->window);
}
