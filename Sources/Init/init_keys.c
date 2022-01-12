/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:17 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/12 11:50:47 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

void	register_loop_hook(t_window *window, int (*f)(), void *param)
{
	mlx_loop_hook(window->mlx, f, param);
}

void	register_key_hook(t_window *window, int (*f)(), void *param)
{
	mlx_key_hook(window->win, f, param);
}
