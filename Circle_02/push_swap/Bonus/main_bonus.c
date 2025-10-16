/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/20 13:11:49 by risattou          #+#    #+#             */
/*   Updated: 2025/01/28 09:46:01 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

static int	ft_check(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (!((av[i] >= '0' && av[i] <= '9') || av[i] == 32 || av[i] == '-'
				|| av[i] == '+'))
			return (ft_error());
		i++;
	}
	return (1);
}

static int	ft_space(char *av)
{
	int	i;

	i = 0;
	while (av[i])
	{
		if (av[i] == 32)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_check_av(int ac, char *av[])
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_check(av[i]) == 0)
			return (0);
		i++;
	}
	i = 1;
	while (i < ac)
	{
		if (ft_space(av[i]) == 1)
		{
			if (ft_split_check(av[i], 32) == 0)
				return (0);
		}
		else if (ft_atoi_check(av[i]) == 0)
			return (0);
		i++;
	}
	return (1);
}

static int	ft_create_list(int ac, char *av[], t_list **head)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (ft_space(av[i]) == 1)
		{
			if (ft_split(av[i], 32, head) == 0)
			{
				ft_lstclear(head);
				return (0);
			}
		}
		else if (ft_lstadd_back(head, ft_lstnew(ft_atoi(av[i]))) == 0)
		{
			ft_lstclear(head);
			return (0);
		}
		i++;
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*head;
	t_list	*stack_a;
	t_list	*stack_b;

	if (ac <= 1)
		return (0);
	if (ft_check_av(ac, av) == 0)
		return (1);
	head = NULL;
	if (ft_create_list(ac, av, &head) == 0)
		return (1);
	stack_a = head;
	stack_b = NULL;
	ft_sortlist(&stack_a);
	if (!ft_read_output(&stack_a, &stack_b))
		return (1);
	if (ft_is_sorted(&stack_a) == 0 && stack_b == NULL)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	ft_lstclear(&stack_a);
	ft_lstclear(&stack_b);
	return (0);
}
