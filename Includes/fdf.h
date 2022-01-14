/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:28:05 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 13:41:26 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

/* LIBRAIRIES */

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <math.h>
# include <mlx.h>
# include "controls.h"
# include "../Get_next_line/get_next_line.h"
# include "../Libft/libft.h"

/* STRUCTS */
	/*Image*/
typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;
	/*Window*/
typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	*title;
	int		width;
	int		height;
	t_img	img;
}			t_window;
	/*Camera*/
typedef struct s_camera
{
	int		zoom;
	double	alpha;
	double	beta;
	double	gamma;
	int		x_offset;
	int		y_offset;
	int		z_divider;
}			t_camera;
	/*3D Vector*/
typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_vec3;
	/*2D Vector*/
typedef struct s_vec2
{
	int	x;
	int	y;
	int	color;
}				t_vec2;
	/*Point*/
typedef struct s_point
{
	int		z;
	int		color;
}				t_point;
	/*Map*/
typedef struct s_map
{
	int		width;
	int		height;
	int		z_max;
	int		z_min;
	t_vec3	**vectors;
	t_point	**coords;
}				t_map;
	/*Project Struct*/
typedef struct s_fdf
{
	t_window	window;
	t_map		*map;
	t_camera	*camera;
	char		projection;
}				t_fdf;

/* SOURCES */
	/*PARSING*/
t_map	*ft_parse_map(char *filename);
	/*UTILS*/
		/*Checks*/
short	check_fd(char *filename);
short	existing_fd(char *filename);
short	check_arg(int ac, char **av);
		/*Draw*/
int		get_index(int x, int y, int width);
t_vec2	vec_add(t_vec2 vec, int x, int y);
t_vec2	vec2_diff(t_vec2 a, t_vec2 b);
t_vec2	get_sign(t_vec2 a, t_vec2 b);
		/*Free*/
void	free_split(char **split);
void	free_all(t_map	*map);
int		close_window(t_fdf *fdf);
void	stop_render(t_window *window);
		/*Parsing*/
size_t	vec_length(t_vec3 **a);
size_t	split_size(char **s);
t_vec3	**join_vectors(t_vec3 **vectors, t_vec3 **c, t_map *map);
		/*Colors*/
int		get_point_color(t_point *point, t_fdf *fdf);
		/*Z (Height)*/
int		ft_atoi_base(char *s);
	/*VECTORS*/
void	verify_vec(t_vec3 *v);
t_vec2	v2f(int x, int y);
t_vec3	*get_z_vec(int x, int y, char *s);
	/*CONVERT*/
void	convert_vec3(t_map **map);
	/*INIT*/
void	init_settings(t_fdf *fdf);
void	register_key_hook(t_window *window, int (*f)(), void *param);
void	register_loop_hook(t_window *window, int (*f)(), void *param);
void	init_controls(t_fdf *fdf);
	/*DISPLAY*/
void	display_map(t_fdf fdf);
void	clear_image(t_fdf *fdf);
t_vec2	projection(t_vec3 point, t_fdf fdf);
int		print_image(t_fdf *fdf);
void	draw_pixel(t_window *window, t_vec2 v, int color);
void	draw_lines(t_fdf fdf);
t_vec3	new_point(int x, int y, t_map *map);

int		get_point_color(t_point *point, t_fdf *fdf);
#endif