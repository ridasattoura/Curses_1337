/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 10:57:35 by risattou          #+#    #+#             */
/*   Updated: 2024/06/29 22:09:54 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str, int n, int b)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, &str[i], 1);
		i++;
	}
	if (b == 1)
		write(1, ", ", 2);
}

char	*ft_arr(char *arr, int n, int j)
{
	int	i;

	i = 0;
	while (i < n)
	{
		arr[i] = (j - n) + i + 48;
		i++;
	}
	return (arr);
}

void	ft_print_combn(int n)
{
	char	valueinitial[10];
	char	valuemax[10];
	int		index;
	int		base;

	ft_arr(valueinitial, n, n);
	ft_arr(valuemax, n, 10);
	index = n - 1;
	ft_putstr(valueinitial, n, 1);
	while (valueinitial[0] != valuemax[0])
	{
		while (valueinitial[index] == valuemax[index])
			index--;
		valueinitial[index] += 1;
		base = valueinitial[index];
		while (index < n - 1)
		{
			index++;
			base++;
			valueinitial[index] = base;
		}
		ft_putstr(valueinitial, n, 0);
		if (valueinitial[0] != valuemax[0])
			write(1, ", ", 2);
	}
}
