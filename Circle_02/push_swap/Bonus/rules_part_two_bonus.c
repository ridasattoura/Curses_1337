/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_two_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 18:49:46 by risattou          #+#    #+#             */
/*   Updated: 2025/02/04 12:28:43 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"
#include <stdio.h>

void	push_a(t_list **stack_a, t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_front(stack_a, tmp);
}

void	rotate_a(t_list **stack_a)
{
	t_list	*tmp;

	if (!stack_a || !*stack_a)
		return ;
	tmp = *stack_a;
	*stack_a = (*stack_a)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_a, tmp);
}

void	rotate_b(t_list **stack_b)
{
	t_list	*tmp;

	if (!stack_b || !*stack_b)
		return ;
	tmp = *stack_b;
	*stack_b = (*stack_b)->next;
	tmp->next = NULL;
	ft_lstadd_back(stack_b, tmp);
}

void	reverse_rotate_a(t_list **stack_a)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	tmp1 = *stack_a;
	while (tmp1->next && tmp1->next->next)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	if (!tmp)
		return ;
	tmp1->next = NULL;
	ft_lstadd_front(stack_a, tmp);
}

void	reverse_rotate_b(t_list **stack_b)
{
	t_list	*tmp1;
	t_list	*tmp;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	tmp1 = *stack_b;
	while (tmp1->next && tmp1->next->next)
		tmp1 = tmp1->next;
	tmp = tmp1->next;
	if (!tmp)
		return ;
	tmp1->next = NULL;
	ft_lstadd_front(stack_b, tmp);
}
