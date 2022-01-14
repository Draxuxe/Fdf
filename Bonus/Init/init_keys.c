/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_keys.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 11:45:17 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 10:37:44 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf_bonus.h"

void	register_loop_hook_bonus(t_window *window, int (*f)(), void *param)
{
	mlx_loop_hook(window->mlx, f, param);
}

void	register_key_hook_bonus(t_window *window, int (*f)(), void *param)
{
	mlx_key_hook(window->win, f, param);
}
