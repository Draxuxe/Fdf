/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   z_utils.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lfilloux <lfilloux@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 16:22:10 by lfilloux          #+#    #+#             */
/*   Updated: 2022/01/14 13:40:19 by lfilloux         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../Includes/fdf.h"

static int	isdigit_base(char c)
{
	const char	*digits = "0123456789ABCDEF";
	int			i;

	i = 0;
	while (i < 16)
	{
		if (digits[i] == ft_toupper(c))
			return (i);
		i++;
	}
	return (-1);
}

static short	has_prefix(char *s)
{
	if (s[0] != '0')
		return (1);
	if (s[1] == 'x' || s[1] == 'X')
		return (1);
	return (0);
}

int	ft_atoi_base(char *s)
{
	unsigned long	result;
	size_t			i;
	int				sign;

	if (!s)
		return (-1);
	i = 0;
	result = 0;
	sign = 1;
	while (s[i] == ' ')
		i ++;
	if (!has_prefix(s))
		return (-10124524);
	i += 2;
	while (isdigit_base(s[i]) >= 0)
		result = result * 16 + isdigit_base(s[i++]);
	return ((int)(result * sign));
}
