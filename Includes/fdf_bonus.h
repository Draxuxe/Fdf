/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/13 17:50:51 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 16:10:08 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_BONUS_H
# define FDF_BONUS_H

# include "fdf.h"
# include "color.h"

/* BONUS */
	/*Colors*/
double	get_light(int start, int end, double percentage);
double	get_percent(int current, int start, int end);
int		get_point_color(t_point *point, t_fdf *fdf);
	/*Projection*/
void	reset_projection(t_fdf *fdf, double a, double b, double g);
double	degree_to_rad(int degree);
	/*Rotations*/
void	rotate_y(t_vec3 *vec, double beta);
void	rotate_x(t_vec3 *vec, double alpha);
void	rotate_z(t_vec3 *vec, double gamma);
	/*Moves and Zooms*/
void	init_settings_bonus(t_fdf *fdf);
void	register_key_hook_bonus(t_window *window, int (*f)(), void *param);
void	register_loop_hook_bonus(t_window *window, int (*f)(), void *param);
void	init_controls_bonus(t_fdf *fdf);

#endif