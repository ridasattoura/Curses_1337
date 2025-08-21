/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 05:23:18 by risattou          #+#    #+#             */
/*   Updated: 2024/07/11 01:01:00 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_check(char *str);
int		ft_strstr(char c, char *base);
int		ft_total(char *str, int j, char *base);
int		ft_atoi_base(char *str, char *base);
void	ft_conteur(int num, char *base, int len, int *i);

int	ft_countnbr_base(int nbr, char *base)
{
	int	i;
	int	j;

	j = 0;
	i = ft_check(base);
	if (i <= 1)
		return (0);
	if (nbr < 0)
	{
		j++;
		ft_conteur(-(nbr / i), base, i, &j);
	}
	else
		ft_conteur(nbr, base, i, &j);
	return (j);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

void	ft_newalloc(char *ptr, int num, char *base, int *i)
{
	int	len;

	len = ft_strlen(base);
	if (num >= len)
		ft_newalloc(ptr, num / len, base, i);
	ptr[*i] = base[num % len];
	(*i)++;
}

char	*ft_putnbr_base(char *ptr, int nbr, char *base, int i)
{
	int	j;

	j = 0;
	if (nbr < 0)
	{
		ptr[j] = '-';
		j++;
		ft_newalloc(ptr, -(nbr / i), base, &j);
		ptr[j] = base[-(nbr % i)];
		j++;
	}
	else
		ft_newalloc(ptr, nbr, base, &j);
	return (ptr);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		len;
	int		len_base;
	int		nb;
	char	*new;

	len = 0;
	len_base = ft_check(base_to);
	if (len_base <= 1)
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	if (nb < 0)
		len++;
	len += ft_countnbr_base(nb, base_to);
	if (len < 1 || nb == 0)
		return (NULL);
	new = malloc(len + 1);
	if (new == NULL)
		return (NULL);
	ft_putnbr_base(new, nb, base_to, len_base);
	new[len] = '\0';
	return (new);
}
