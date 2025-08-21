/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_one.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:55 by risattou          #+#    #+#             */
/*   Updated: 2025/01/22 12:44:22 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static void	swap_node(t_list *stack_a, t_list *stack_b)
{
	int	tmp;
	int	tmpi;

	if (!stack_b)
		return ;
	tmp = stack_a->nb;
	tmpi = stack_a->index;
	stack_a->index = stack_b->index;
	stack_b->index = tmpi;
	stack_a->nb = stack_b->nb;
	stack_b->nb = tmp;
}

void	swap_a(t_list **stack_a)
{
	if (!stack_a || !*stack_a)
		return ;
	swap_node(*stack_a, (*stack_a)->next);
	ft_putstr_fd("sa\n", 1);
}

void	swap_b(t_list **stack_b)
{
	if (!stack_b || !*stack_b)
		return ;
	swap_node(*stack_b, (*stack_b)->next);
	ft_putstr_fd("sb\n", 1);
}

void	push_b(t_list **stack_b, t_list **stack_a)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("pb\n", 1);
}
