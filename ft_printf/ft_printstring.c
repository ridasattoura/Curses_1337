/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstring.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:34 by risattou          #+#    #+#             */
/*   Updated: 2024/11/28 16:33:33 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str && str[i] != '\0')
		i++;
	return (i);
}

int	ft_printstring(char *str, t_flag *flag)
{
	int	count;
	int	len;

	count = 0;
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (flag && flag->full_stop >= 0 && flag->full_stop < len)
		len = flag->full_stop;
	if (flag && flag->dash == 0 && flag->number > len)
	{
		flag->number -= len;
		while (flag->number-- > 0)
			count += ft_putchar(' ', 0);
	}
	while (*str != '\0' && len--)
		count += ft_putchar(*str++, 0);
	if (flag && flag->dash == 1 && flag->number > count)
	{
		flag->number -= count;
		while (flag->number-- > 0)
			count += ft_putchar(' ', 0);
	}
	return (count);
}
