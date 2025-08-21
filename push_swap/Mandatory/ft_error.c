/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:27:41 by risattou          #+#    #+#             */
/*   Updated: 2025/01/28 09:50:40 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_error(void)
{
	ft_putstr_fd("Error\n", 2);
	return (0);
}

int	ft_error_node(t_list *new_node)
{
	free(new_node);
	return (ft_error());
}
