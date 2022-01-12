/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:39:26 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/12 14:28:48 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	display_map(t_fdf fdf)
{
	init_controls(&fdf);
	mlx_loop(fdf.window.mlx);
	stop_render(&fdf.window);
	free_all(fdf.map);
}
