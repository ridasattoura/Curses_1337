/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sortlist_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:39:54 by risattou          #+#    #+#             */
/*   Updated: 2025/01/21 12:45:37 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_sortlist(t_list **stack_a)
{
	t_list	*tmp;
	t_list	*check;
	int		i;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	while (tmp)
	{
		i = 0;
		check = *stack_a;
		while (check)
		{
			if ((check->nb < tmp->nb))
				i++;
			check = check->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}
