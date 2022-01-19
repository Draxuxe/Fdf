/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:55:49 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/19 13:16:20 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

short	check_arg(int ac, char **av)
{
	if (ac != 2)
	{
		errno = 22;
		perror ("Wrong number of arguments");
		return (0);
	}
	else if (!existing_fd(av[1]))
	{
		errno = 22;
		perror ("Nothing turned in");
		return (0);
	}
	else if (!check_fd(av[1]))
	{
		errno = 22;
		perror ("Wrong file descriptor type");
		return (0);
	}
	return (1);
}

short	check_fd(char *filename)
{
	size_t	i;

	i = ft_strlen(filename);
	if (filename[i - 1] == 'f' && filename[i - 2] == 'd'
		&& filename[i - 3] == 'f' && filename[i - 4] == '.')
		return (1);
	return (0);
}

short	existing_fd(char *filename)
{
	if (!filename)
		return (0);
	return (1);
}
