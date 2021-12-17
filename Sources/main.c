/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 09:31:55 by lfilloux          #+#    #+#             */
/*   Updated: 2021/12/17 17:41:34 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (!check_arg(ac, av))
		return (-1);
	fdf.map = ft_parse_map(av[1]);
	display_map(&fdf);
	return (0);
}
