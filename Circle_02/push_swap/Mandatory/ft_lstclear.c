/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:59:50 by risattou          #+#    #+#             */
/*   Updated: 2025/01/20 18:52:23 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

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
