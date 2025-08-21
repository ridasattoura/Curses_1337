/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 00:04:17 by risattou          #+#    #+#             */
/*   Updated: 2024/07/08 22:00:19 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		if (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13))
			return (1);
		if (str[i] == '-' || str[i] == '+')
			return (1);
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (1);
			j++;
		}
		i++;
	}
	return (i);
}

int	ft_strstr(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_total(char *str, int j, char *base)
{
	int	res;
	int	i;

	res = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (ft_strstr(str[i], base) >= 0)
			res = res * j + ft_strstr(str[i], base);
		else
			break ;
		i++;
	}
	return (res);
}

int	ft_atoi_base(char *str, char *base)
{
	int	sign;
	int	i;

	sign = 1;
	i = 0;
	if (ft_check(base) <= 1)
		return (0);
	while (str[i] != '\0' && (str[i] == ' ' || (str[i] >= 9 && str[i] <= 13)))
		i++;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
		i++;
	}
	return ((ft_total((str + i), ft_check(base), base)) * sign);
}
