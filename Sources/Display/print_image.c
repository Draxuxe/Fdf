/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:57:30 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/20 14:57:33 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	draw_line(t_window *window, t_vec2 a, t_vec2 b)
{
	t_vec2	delta;
	t_vec2	sign;
	t_vec2	current;
	int		error[2];

	delta = vec2_diff(a, b);
	sign = get_sign(a, b);
	error[0] = delta.x + delta.y;
	current = a;
	while ()
}

static void	draw_pixel(t_window *window, t_vec2 v, int color)
{
	char	*pixel;
	int		i;
	t_img	*image;

	image = &window->img;
	i = image->bpp - 8;
	pixel = image->addr + (v.y * image->line_len + v.x * (image->bpp / 8));
	while (i >= 0)
	{
		if (image->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (image->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

static void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	t_point	*point;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			point = fdf.map->coords[get_index(x, y, fdf.map->width)];
			if (x != fdf.map->width - 1)
				draw_line(&fdf.window, projection(new_point(x, y,
							fdf.map), fdf), projection(new_point(x + 1, y,
							fdf.map), fdf));
			if (y != fdf.map->height - 1)
				draw_line(&fdf.window, projection(new_point(x, y,
							fdf.map), fdf), projection(new_point(x + 1, y,
							fdf.map), fdf));
			x++;
		}
		y++;
	}
}

static void	clear_image(t_fdf *fdf)
{
	int	x;
	int	y;

	y = 0;
	while (y < fdf->window.height)
	{
		x = 0;
		while (x < fdf->window.width)
		{
			draw_pixel(&fdf->window, v2f(x, y), BACKGROUND);
			x ++;
		}
		y ++;
	}
}

void	print_image(t_fdf *fdf)
{
	clear_image(fdf);
	draw_lines(*fdf);
	mlx_put_image_to_window(fdf->window.mlx,
		fdf->window.win, fdf->window.img.mlx_img, 0, 0);
}
