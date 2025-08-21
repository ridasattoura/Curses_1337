/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helpnumber.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/27 05:07:42 by risattou          #+#    #+#             */
/*   Updated: 2024/11/27 09:42:01 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_hash(char *base)
{
	int	count;

	count = 0;
	if (base[10] == 'a')
		count += ft_printstring("0x", 0);
	else if (base[10] == 'A')
		count += ft_printstring("0X", 0);
	return (count);
}

int	ft_zero(t_flag *flag, int len, char *base)
{
	int	count;

	count = 0;
	if (flag->full_stop >= len)
	{
		while (flag->full_stop > len)
		{
			write(1, "0", 1);
			count ++; 
			flag->full_stop--;
		}
		return (count);
	}
	if (flag->hash == 2)
		count += ft_hash(base);
	flag->hash = 0;
	while (flag && flag->number > 0)
	{
		write(1, "0", 1);
		count ++; 
		flag->number--;
	}
	return (count);
}

void	ft_helper(t_flag *flag, int *count, int len, char *base)
{
	flag->number -= (len + *count + flag->hash);
	if (flag->zero == 0)
		*count += ft_putchar(' ', flag);
	if (flag->zero == 1)
		*count += ft_zero(flag, 1, base);
}
