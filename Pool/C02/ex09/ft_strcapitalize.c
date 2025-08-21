/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcapitalize.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:35:04 by risattou          #+#    #+#             */
/*   Updated: 2024/07/01 15:46:39 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_alphanumeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else if (c >= 97 && c <= 122)
		return (2);
	else if (c >= 65 && c <= 90)
		return (3);
	return (0);
}

char	*ft_strlowcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_alphanumeric(str[i]) == 3)
			str[i] += 32;
		i++;
	}
	return (str);
}

char	*ft_strcapitalize(char *st1)
{
	int		i;
	int		cond;
	char	*str;

	i = 0;
	cond = 1;
	str = ft_strlowcase(st1);
	while (str[i] != 0)
	{
		if (ft_alphanumeric(str[i]) == 0)
			cond = 1;
		else if (ft_alphanumeric(str[i]) == 1)
			cond = 0;
		else if (ft_alphanumeric(str[i]) == 2 && cond == 1)
		{
			str[i] -= 32;
			cond = 0;
		}
		i++;
	}
	return (str);
}
