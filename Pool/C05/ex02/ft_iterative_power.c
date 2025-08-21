/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 21:55:20 by risattou          #+#    #+#             */
/*   Updated: 2024/07/08 02:04:01 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	nbr;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	nbr = nb;
	while (power > 1)
	{
		nbr *= nb;
		power--;
	}
	return (nbr);
}
