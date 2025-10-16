/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rules_part_three_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/22 11:02:01 by risattou          #+#    #+#             */
/*   Updated: 2025/01/22 13:05:45 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	rotate_a_b(t_list **stack_b, t_list **stack_a)
{
	rotate_a(stack_a);
	rotate_b(stack_b);
}

void	swap_a_b(t_list **stack_b, t_list **stack_a)
{
	swap_a(stack_a);
	swap_b(stack_b);
}

void	reverse_rotate_a_b(t_list **stack_b, t_list **stack_a)
{
	reverse_rotate_a(stack_a);
	reverse_rotate_b(stack_b);
}
