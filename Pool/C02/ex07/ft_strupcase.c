/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strupcase.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/28 20:34:58 by risattou          #+#    #+#             */
/*   Updated: 2024/07/01 15:38:38 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_check_case(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

char	*ft_strupcase(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_check_case(str[i]) == 1)
			str[i] -= 32;
		i++;
	}
	return (str);
}
