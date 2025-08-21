/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:59:50 by risattou          #+#    #+#             */
/*   Updated: 2025/01/21 12:45:20 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

void	ft_lstclear(t_list **lst)
{
	t_list	*head;
	t_list	*new;

	if (!lst)
		return ;
	head = *lst;
	while (head != NULL)
	{
		new = head->next;
		free(head);
		head = new;
	}
	*lst = NULL;
}
