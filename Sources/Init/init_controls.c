/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 10:05:06 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 18:02:05 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static int	dispatch_keys(int keycode, t_fdf *fdf)
{
	if (keycode == ESC)
	{
		stop_render(&fdf->window);
		free_all(fdf->map);
	}
	return (0);
}

void	init_controls(t_fdf *fdf)
{
	print_image(fdf);
	register_key_hook(&fdf->window, dispatch_keys, fdf);
	mlx_hook(fdf->window.win, 17, 0, close_window, fdf);
}
