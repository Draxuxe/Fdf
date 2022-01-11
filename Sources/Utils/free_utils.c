/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 17:45:31 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/10 17:16:25 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	free_all(t_map	*map)
{
	size_t	i;

	i = 0;
	while (map->vectors[i])
	{
		free(map->vectors[i]);
		i ++;
	}
	i = 0;
	while (map->coords[i])
	{
		free (map->coords[i]);
		i ++;
	}
	free(map->vectors);
	free (map->coords);
	free (map);
}

void	stop_render(t_window *window)
{
	mlx_destroy_image(window->mlx, window->img.mlx_img);
	mlx_destroy_window(window->mlx, window->win);
}
