/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnumber.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:31 by risattou          #+#    #+#             */
/*   Updated: 2024/11/27 05:06:20 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_len(char *base)
{
	int	i;

	i = 0;
	while (base[i])
		i++;
	return (i);
}

static int	ft_printr(unsigned int num, char *base, unsigned int len)
{
	int	count;

	count = 0;
	if (num >= len)
	{
		count += ft_printr(num / len, base, len);
		count += ft_printr(num % len, base, len);
	}
	else
		count += ft_putchar(base[num], 0);
	return (count);
}

int	ft_printnumber(unsigned int nbr, char *base, t_flag *flag)
{
	int	count;
	int	len;

	count = 0;
	len = ft_countnbr_base(nbr, ft_len(base), flag);
	if (flag && ((len < flag->full_stop) || (nbr == 0 && flag->full_stop == 0)))
		len = flag->full_stop;
	if (flag && ((flag->dash == 0 && flag->number > count + len + flag->hash)))
		ft_helper(flag, &count, len, base);
	if (flag && flag->hash == 2)
		count += ft_hash(base);
	if (flag && (flag->full_stop >= ft_countnbr_base(nbr, ft_len(base), flag)))
		count += ft_zero(flag, ft_countnbr_base(nbr, ft_len(base), flag), base);
	if (flag && !(nbr == 0 && flag->full_stop > -1))
		count += ft_printr(nbr, base, ft_len(base));
	if (flag && flag->dash == 1 && flag->number > count)
	{
		flag->number -= count;
		count += ft_putchar(' ', flag);
	}
	return (count);
}
