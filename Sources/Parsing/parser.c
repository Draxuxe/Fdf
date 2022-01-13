/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:02:30 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/13 17:10:17 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static t_map	*create_map(void)
{
	t_map	*map;

	map = (t_map *)malloc(sizeof(t_map));
	if (!map)
	{
		free(map);
		exit(EXIT_FAILURE);
	}
	map->z_max = 0;
	map->z_min = 0;
	return (map);
}

static t_vec3	**parse_line(char *line, int y)
{
	t_vec3	**vectors;
	t_vec3	*tmp;
	char	**s;
	int		i;

	if (!line)
		return (NULL);
	s = ft_split(line, ' ');
	i = 0;
	vectors = malloc(sizeof(t_vec3 *) * (split_size(s) + 1));
	if (!vectors)
		return (NULL);
	while (s[i])
	{
		tmp = get_z_vec(i, y, s[i]);
		verify_vec(tmp);
		vectors[i] = tmp;
		free (s[i]);
		i ++;
	}
	free(s);
	free(line);
	vectors[i] = 0;
	return (vectors);
}

static t_map	*get_map(int fd)
{
	t_map	*map;
	t_vec3	**c;
	t_vec3	**vectors;
	char	*line;

	line = get_next_line(fd);
	if (!line)
		return (NULL);
	map = create_map();
	map->height = 0;
	vectors = parse_line(line, map->height);
	map->height++;
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		c = parse_line(line, map->height);
		vectors = join_vectors(vectors, c, map);
		map->height++;
	}
	map->vectors = vectors;
	return (map);
}

t_map	*ft_parse_map(char *filename)
{
	int		fd;
	t_map	*map;

	fd = open (filename, O_RDONLY);
	if (fd < 0)
	{
		errno = 22;
		perror ("This file descriptor doesn't exist");
		exit (EXIT_FAILURE);
	}
	map = get_map(fd);
	if (!map || map->height == 0)
	{
		errno = 22;
		perror ("Can't work with this map");
		exit (EXIT_FAILURE);
	}
	close (fd);
	convert_vec3(&map);
	return (map);
}
