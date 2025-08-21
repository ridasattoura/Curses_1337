/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_two.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:46 by risattou          #+#    #+#             */
/*   Updated: 2025/01/22 12:45:06 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("pa\n", 1);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
	ft_putstr_fd("ra\n", 1);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
	ft_putstr_fd("rb\n", 1);
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!(*stack_a))
		return ;
	tmp1 = *stack_a;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_a, tmp);
	ft_putstr_fd("rra\n", 1);
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!(*stack_b))
		return ;
	tmp1 = *stack_b;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	tmp1->next = NULL;
	ft_lstadd_front(stack_b, tmp);
	ft_putstr_fd("rrb\n", 1);
}
