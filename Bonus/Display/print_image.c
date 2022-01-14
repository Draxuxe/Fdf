/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_image.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/20 10:57:30 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 10:31:59 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

void	draw_pixel(t_window *window, t_vec2 v, int color)
{
	int		i;
	t_img	*img;

	img = &window->img;
	if (!(v.x > 0 && v.x < window->width && v.y > 0 && v.y < window->height))
		return ;
	i = (v.x * img->bpp / 8) + (v.y * img->line_len);
	img->addr[i] = color;
	img->addr[++i] = color >> 8;
	img->addr[++i] = color >> 16;
}

static void	draw_line(t_window *window, t_vec2 a, t_vec2 b, int color)
{
	t_vec2	delta;
	t_vec2	sign;
	t_vec2	current;
	int		error[2];

	(void) color;
	delta = vec2_diff(a, b);
	sign = get_sign(a, b);
	error[0] = delta.x + delta.y;
	current = a;
	while (current.x != b.x && current.y != b.y)
	{
		draw_pixel(window, current, color);
		error[1] = 2 * error[0];
		if (error[1] >= delta.y)
		{
			error[0] += delta.y;
			current.x += sign.x;
		}
		if (error[1] <= delta.x)
		{
			error[0] += delta.x;
			current.y += sign.y;
		}
	}
}

static void	draw_line_x(int x, int y, t_fdf fdf, int color)
{
	draw_line(&fdf.window, projection(new_point(x + 1, y,
				fdf.map), fdf), projection(new_point(x, y,
				fdf.map), fdf), color);
	draw_line(&fdf.window, projection(new_point(x, y,
				fdf.map), fdf), projection(new_point(x + 1, y,
				fdf.map), fdf), color);
}

static void	draw_line_y(int x, int y, t_fdf fdf, int color)
{
	draw_line(&fdf.window, projection(new_point(x, y + 1,
				fdf.map), fdf), projection(new_point(x, y,
				fdf.map), fdf), color);
	draw_line(&fdf.window, projection(new_point(x, y,
				fdf.map), fdf), projection(new_point(x, y + 1,
				fdf.map), fdf), color);
}

void	draw_lines(t_fdf fdf)
{
	int		x;
	int		y;
	int		color;
	t_point	*point;

	y = 0;
	while (y < fdf.map->height)
	{
		x = 0;
		while (x < fdf.map->width)
		{
			point = fdf.map->coords[get_index(x, y, fdf.map->width)];
			color = get_point_color(point, &fdf);
			if (x != fdf.map->width - 1)
				draw_line_x(x, y, fdf, color);
			if (y != fdf.map->height - 1)
				draw_line_y(x, y, fdf, color);
			x++;
		}
		y++;
	}
}
