/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnegativ.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:28 by risattou          #+#    #+#             */
/*   Updated: 2024/11/27 04:53:37 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_help(t_flag *flag, int len, long nbr)
{
	int	count;

	count = 0;
	flag->number -= (len + flag->plus);
	if (len == flag->full_stop && nbr < 0)
		flag->number--;
	if (!(nbr < 0 && flag->number == 0))
		count += ft_putchar(' ', flag);
	flag->space = 0;
	flag->number = 0;
	return (count);
}

static int	ft_plus_space(t_flag *flag)
{
	int	count;

	count = 0;
	if (flag->plus == 1)
		count += ft_putchar('+', 0);
	else if (flag->space == 1)
		count += ft_putchar(' ', 0);
	flag->number--;
	return (count);
}

int	ft_printnegative(int nb, t_flag *flag)
{
	int		count;
	long	nbr;
	int		len;

	nbr = (long)nb;
	count = 0;
	len = ft_countnbr(nbr);
	if (nbr < 0)
		flag->plus = 0;
	if (flag && ((len < flag->full_stop) || (nbr == 0 && flag->full_stop == 0)))
		len = flag->full_stop;
	if (flag && flag->dash == 0 && flag->zero == 0 && flag->number > len
		+ flag->plus)
		count += ft_help(flag, len, nbr);
	if (flag && (flag->space == 1 || flag->plus == 1) && nbr > -1)
		count += ft_plus_space(flag);
	if (nbr < 0)
	{
		count += ft_putchar('-', 0);
		flag->number--;
		return (count + ft_printnumber((-nbr), "0123456789", flag));
	}
	return (count + ft_printnumber((nbr), "0123456789", flag));
}
