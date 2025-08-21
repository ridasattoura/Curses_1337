/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_choose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 15:27:22 by risattou          #+#    #+#             */
/*   Updated: 2024/11/28 16:24:25 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_choose(const char **str, va_list *args, t_flag *flag)
{
	int	count;

	count = 0;
	if (**str == 'd' || **str == 'i')
		count += ft_printnegative(va_arg(*args, int), flag);
	else if (**str == 'c')
		count += ft_putchar(va_arg(*args, int), flag);
	else if (**str == 's')
		count += ft_printstring(va_arg(*args, char *), flag);
	else if (**str == 'u')
		count += ft_printnumber(va_arg(*args, unsigned int), "0123456789",
				flag);
	else if (**str == 'X')
		count += ft_printnumber(va_arg(*args, unsigned int), "0123456789ABCDEF",
				flag);
	else if (**str == 'x')
		count += ft_printnumber(va_arg(*args, unsigned int), "0123456789abcdef",
				flag);
	else if (**str == 'p')
		count += ft_printptr(va_arg(*args, size_t), "0123456789abcdef", flag);
	else if (**str == '%')
		count += ft_putchar('%', flag);
	if (**str)
		(*str)++;
	return (count);
}
