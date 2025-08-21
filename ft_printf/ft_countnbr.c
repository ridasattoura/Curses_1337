/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_countnbr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/28 16:33:15 by risattou          #+#    #+#             */
/*   Updated: 2024/11/28 16:33:59 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_countnbr(long nbr)
{
	int	i;

	i = 0;
	if (nbr == 0)
		return (1);
	if (nbr < 0)
	{
		nbr *= (-1);
		i++;
	}
	while (nbr > 0)
	{
		nbr /= 10;
		i++;
	}
	return (i);
}

int	ft_countnbr_base(unsigned int nbr, int len, t_flag *flag)
{
	int	i;

	i = 0;
	if (flag && nbr == 0 && flag->full_stop > -1)
	{
		flag->hash = 0;
		return (0);
	}
	if (nbr == 0)
	{
		flag->hash = 0;
		return (1);
	}
	while (nbr > 0)
	{
		nbr /= len;
		i++;
	}
	return (i);
}
