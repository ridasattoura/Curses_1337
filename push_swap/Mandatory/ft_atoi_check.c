/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_check.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:16:56 by risattou          #+#    #+#             */
/*   Updated: 2025/01/20 13:34:12 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	check(const char *str)
{
	int	i;
	int	last_was_space;

	i = 0;
	last_was_space = 0;
	while (str[i])
	{
		if (str[i] == ' ')
			last_was_space = 1;
		else
		{
			if (i > 0 && (str[i] == '-' || str[i] == '+') && !last_was_space)
				return (2);
			last_was_space = 0;
		}
		i++;
	}
	return (0);
}

int	ft_strlen(const char *str)
{
	int	i;
	int	g;

	i = 0;
	g = 0;
	while (str[i + g] != '\0' && str[i + g] == 48)
		g++;
	while (str[i + g] != '\0' && (str[i + g] >= 48 && str[i + g] <= 57))
		i++;
	return (i);
}

int	ft_atoi_check(const char *str)
{
	long	result;
	long	sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if ((check(str) == 2) || (ft_strlen(str) > 11))
		return (ft_error());
	if (str[i] == '+' || str[i] == '-')
	{
		i++;
		sign = -1;
	}
	if (!(str[i] >= 48 && str[i] <= 57))
		return (ft_error());
	while (str[i] >= 48 && str[i] <= 57)
	{
		result = result * 10 + str[i] - 48;
		i++;
	}
	result *= sign;
	if (i == 0 || (result > 2147483647) || (result < -2147483648))
		return (ft_error());
	return (1);
}
