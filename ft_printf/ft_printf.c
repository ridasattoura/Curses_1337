/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:18 by risattou          #+#    #+#             */
/*   Updated: 2024/11/27 15:56:00 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_atoi(const char **str)
{
	int	result;

	result = 0;
	while (**str >= 48 && **str <= 57)
	{
		result = result * 10 + **str - 48;
		(*str)++;
	}
	return (result);
}

static void	ft_flage(const char **str, t_flag *flag)
{
	while (**str == ' ' || **str == '+' || **str == '#' || **str == '0'
		|| **str == '-')
	{
		if (**str == ' ')
			flag->space = 1;
		else if (**str == '+')
			flag->plus = 1;
		else if (**str == '#')
			flag->hash = 2;
		else if (**str == '0')
			flag->zero = 1;
		else if (**str == '-')
			flag->dash = 1;
		(*str)++;
	}
	if (**str >= 48 && **str <= 57)
		flag->number = ft_atoi(str);
	if (**str == '.')
	{
		(*str)++;
		flag->zero = 0;
		flag->full_stop = 0;
		if (**str >= 48 && **str <= 57)
			flag->full_stop = ft_atoi(str);
	}
}

static void	ft_reset(t_flag *flag)
{
	flag->dash = 0;
	flag->number = 0;
	flag->space = 0;
	flag->full_stop = -1;
	flag->zero = 0;
	flag->plus = 0;
	flag->hash = 0;
}

int	ft_printf(const char *str, ...)
{
	int		count;
	t_flag	flag;
	va_list	args;

	va_start(args, str);
	count = 0;
	while (*str)
	{
		ft_reset(&flag);
		if (*str == '%')
		{
			str++;
			ft_flage(&str, &flag);
			count += ft_choose(&str, &args, &flag);
		}
		else
			count += ft_putchar(*str++, 0);
	}
	va_end(args);
	return (count);
}
