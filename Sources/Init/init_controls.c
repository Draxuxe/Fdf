/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:05:06 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/12 16:27:51 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static void	rotation_controls(int keycode, t_fdf *fdf)
{
	if (keycode == W)
		fdf->camera->alpha += 0.5;
	else if (keycode == S)
		fdf->camera->alpha -= 0.5;
	else if (keycode == A)
		fdf->camera->beta += 0.5;
	else if (keycode == D)
		fdf->camera->beta -= 0.5;
	else if (keycode == Z)
		fdf->camera->gamma += 0.5;
	else if (keycode == X)
		fdf->camera->gamma -= 0.5;
	else if (keycode == PLUS)
	{
		if (fdf->camera->z_divider > 1)
			fdf->camera->z_divider -= 1;
	}
	else if (keycode == MINUS)
		fdf->camera->z_divider += 1;
}

static void	movement_controls(int keycode, t_fdf *fdf)
{
	if (keycode == LEFT)
		fdf->camera->x_offset -= 10;
	else if (keycode == RIGHT)
		fdf->camera->x_offset += 10;
	else if (keycode == DOWN)
		fdf->camera->y_offset += 10;
	else if (keycode == UP)
		fdf->camera->y_offset -= 10;
	clear_image(fdf);
	print_image(fdf);
}

static int	zoom_controls(int keycode, int x, int y, t_fdf *fdf)
{
	(void) x;
	(void) y;
	if (keycode == ZOOM_IN)
		fdf->camera->zoom += 3;
	else if (keycode == ZOOM_OUT)
	{
		fdf->camera->zoom -= 3;
		if (fdf->camera->zoom < 0)
			fdf->camera->zoom = 1;
	}
	clear_image(fdf);
	print_image(fdf);
	return (0);
}

static int	dispatch_keys(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		stop_render(&fdf->window);
		free_all(fdf->map);
	}
	if (keycode == P)
	{
		if (fdf->projection == 'I')
			fdf->projection = 'P';
		else
			fdf->projection = 'I';
		fdf->camera->alpha = 0;
		fdf->camera->beta = 0;
		fdf->camera->gamma = 0;
	}
	rotation_controls(keycode, fdf);
	movement_controls(keycode, fdf);
	zoom_controls(keycode, 0, 0, fdf);
	usleep(1000);
	return (0);
}

void	init_controls(t_fdf *fdf)
{
	print_image(fdf);
	register_key_hook(&fdf->window, dispatch_keys, fdf);
	mlx_hook(fdf->window.win, ZOOM_IN, 0, zoom_controls, fdf);
	mlx_hook(fdf->window.win, 17, 0, close_window, fdf);
}
