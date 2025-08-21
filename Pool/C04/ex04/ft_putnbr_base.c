/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:42:48 by risattou          #+#    #+#             */
/*   Updated: 2024/07/04 18:25:00 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_check(char *base)
{
	int	i;
	int	j;

	i = 0;
	while (base[i])
	{
		j = i + 1;
		if (base[i] == ' ' || (base[i] >= 9 && base[i] <= 13))
			return (1);
		if (base[i] == '+' || base[i] == '-')
			return (1);
		while (base[j])
		{
			if (base[i] == base[j])
				return (1);
			j++;
		}
		i++;
	}
	return (i);
}

void	ft_printr(int num, char *base, int len)
{
	if (num < 0)
	{
		ft_putchar('-');
		num *= (-1);
		ft_printr(num, base, len);
	}
	else if (num >= len)
	{
		ft_printr(num / len, base, len);
		ft_printr(num % len, base, len);
	}
	else
		ft_putchar(base[num]);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int	i;

	i = ft_check(base);
	if (i <= 1)
		return ;
	if (nbr == -2147483648)
	{
		ft_putchar('-');
		ft_printr(-(nbr / i), base, i);
		ft_putchar(base[-(nbr % i)]);
		return ;
	}
	ft_printr(nbr, base, i);
}
