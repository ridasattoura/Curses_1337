/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_sort_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:47:38 by risattou          #+#    #+#             */
/*   Updated: 2025/01/22 13:26:34 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	ft_check_rule(t_list **stack_a, t_list **stack_b, char *str)
{
	if (!ft_strcmp(str, "sa\n"))
		swap_a(stack_a);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b(stack_b);
	else if (!ft_strcmp(str, "ss\n"))
		swap_a_b(stack_a, stack_b);
	else if (!ft_strcmp(str, "pa\n"))
		push_a(stack_a, stack_b);
	else if (!ft_strcmp(str, "pb\n"))
		push_b(stack_b, stack_a);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a(stack_a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b(stack_b);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_a_b(stack_a, stack_b);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_a(stack_a);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_b(stack_b);
	else if (!ft_strcmp(str, "rrr\n"))
		reverse_rotate_a_b(stack_a, stack_b);
	else
		return (ft_error_r(&str));
	return (1);
}

int	ft_read_output(t_list **stack_a, t_list **stack_b)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (str == NULL)
			break ;
		if (ft_check_rule(stack_a, stack_b, str) == 0)
		{
			free(str);
			ft_lstclear(stack_a);
			ft_lstclear(stack_b);
			return (0);
		}
		free(str);
	}
	return (1);
}
