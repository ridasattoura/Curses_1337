/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:41 by risattou          #+#    #+#             */
/*   Updated: 2025/01/28 09:56:26 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_error_r(char **str)
{
	if (!(*str))
		free(*str);
	close(1);
	get_next_line(1);
	return (ft_error());
}

int	ft_error_node(t_list *new)
{
	free(new);
	return (ft_error());
}
