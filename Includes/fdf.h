/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:28:05 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/17 17:46:59 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h>
# include <errno.h>
# include <mlx.h>
# include "../Get_next_line/get_next_line.h"
# include "../Libft/libft.h"

/* Struct map */

typedef struct s_img
{
	void	*mlx_img;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
}				t_img;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	char	*title;
	int		width;
	int		height;
	t_img	img;
}			t_window;

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

typedef struct s_vec3
{
	int	x;
	int	y;
	int	z;
	int	color;
}				t_vec3;

typedef struct s_point
{
	int		z;
	int		color;
}				t_point;

typedef struct s_map
{
	int		width;
	int		height;
	t_vec3	**vectors;
	t_point	**coords;
}				t_map;

typedef struct s_fdf
{
	t_window	window;
	t_map		*map;
	t_camera	*camera;
	char		projection;
}				t_fdf;

/* Fonction sources */

t_map	*ft_parse_map(char *filename);

/* Fonctions utiles */

short	check_fd(char *filename);
short	existing_fd(char *filename);
t_vec3	**join_vectors(t_vec3 **vectors, t_vec3 **c, t_map *map);
t_vec3	*get_z_vec(int x, int y, char *s);
t_vec3	**join_vectors(t_vec3 **vectors, t_vec3 **c, t_map *map);
size_t	split_size(char **s);
int		ft_atoi_base(char *s);
void	verify_vec(t_vec3 *v);
size_t	vec_length(t_vec3 **a);
void	convert_vec3(t_map **map);
short	check_arg(int ac, char **av);
void	display_map(t_fdf *fdf);
void	free_all(t_map	*map);

#endif