/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:31:55 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/13 16:49:46 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int ac, char **av)
{
	t_map	*map;
	void	*mlx;
	void	*mlx_window;

	if (ac != 2)
	{
		errno = 22;
		perror ("Wrong number of arguments");
		return (-1);
	}
	if (!existing_fd(av[1]))
	{
		errno = 22;
		perror ("Nothing turned in");
		return (-1);
	}
	if (!check_fd(av[1]))
	{
		errno = 22;
		perror ("Wrong file descriptor type");
		return (-1);
	}
	map = ft_parse_map(av[1]);
	/*int	i = 0;
	while (map->vectors[i])
	{
		printf("X: %d Y: %d Z: %d\n", map->vectors[i]->x, map->vectors[i]->y,map-> vectors[i]->z);
		i++;
	}*/
	mlx = mlx_init();
	mlx_window = mlx_new_window(mlx, 1920, 1080, "Fdf");
	mlx_loop(mlx);
	return (0);
}
