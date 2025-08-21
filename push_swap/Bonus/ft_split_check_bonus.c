/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_check_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:59:42 by risattou          #+#    #+#             */
/*   Updated: 2025/01/21 12:45:42 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	ft_count(char const *str, char c)
{
	int	i;
	int	cont;

	i = 0;
	cont = 0;
	while (str[i] != '\0')
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
			cont++;
		while (str[i] != c && str[i])
			i++;
	}
	return (cont);
}

static int	ft_home(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			if (ft_atoi_check((char *)(str + i)) == 0)
				return (0);
		}
		while (str[i] != c && str[i])
			i++;
	}
	return (1);
}

int	ft_split_check(char const *str, char c)
{
	if (ft_count(str, c) == 0)
		return (ft_error());
	return (ft_home((char *)str, c));
}
