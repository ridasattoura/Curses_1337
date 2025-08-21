/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 19:29:02 by risattou          #+#    #+#             */
/*   Updated: 2024/10/31 13:42:12 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_nmbr(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= (-1);
		i++;
	}
	while (n > 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		nmbr;
	long	nm;
	char	*new;

	nm = (long)n;
	nmbr = ft_count_nmbr(nm);
	new = malloc(nmbr + 1);
	if (new == NULL)
		return (NULL);
	new[nmbr] = '\0';
	if (nm < 0)
	{
		new[0] = '-';
		nm *= (-1);
	}
	if (nm == 0)
		new[0] = '0';
	while (nm > 0)
	{
		nmbr--;
		new[nmbr] = (nm % 10) + 48;
		nm /= 10;
	}
	return (new);
}
