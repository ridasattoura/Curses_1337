/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:47:38 by risattou          #+#    #+#             */
/*   Updated: 2025/02/04 10:15:44 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	ft_position(t_list **stack_b, int max)
{
	t_list	*tmp;
	int		i;

	tmp = *stack_b;
	i = 0;
	while (tmp != NULL)
	{
		if (tmp->index == max)
			return (i);
		tmp = tmp->next;
		i++;
	}
	return (i);
}

static void	ft_part_one(t_list **stack_a, t_list **stack_b, int max)
{
	int	range_x;
	int	range_y;

	range_x = 0;
	range_y = max * 0.05 + 15;
	while (*stack_a != NULL)
	{
		if ((*stack_a)->index >= range_x && (*stack_a)->index <= range_y)
		{
			push_b(stack_b, stack_a);
			range_x++;
			range_y++;
		}
		else if ((*stack_a)->index < range_x)
		{
			push_b(stack_b, stack_a);
			rotate_b(stack_b);
			range_x++;
			range_y++;
		}
		else if ((*stack_a)->index > range_y)
			rotate_a(stack_a);
	}
	return ;
}

void	ft_sort(t_list **stack_a, t_list **stack_b)
{
	int	max;
	int	tmp;

	max = ft_lstsize((*stack_a)) - 1;
	if (max < 5)
		return (sort_five_or_less(stack_a, stack_b));
	ft_part_one(stack_a, stack_b, max);
	while (*stack_b != NULL)
	{
		tmp = ft_position(stack_b, max);
		if (tmp <= max / 2)
			rotate_b(stack_b);
		else if (tmp > max / 2)
			reverse_rotate_b(stack_b);
		if ((*stack_b)->index == max)
		{
			push_a(stack_a, stack_b);
			max--;
		}
	}
}
