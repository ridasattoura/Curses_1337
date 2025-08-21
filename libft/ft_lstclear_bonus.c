/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 07:59:50 by risattou          #+#    #+#             */
/*   Updated: 2024/11/01 00:11:51 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !del)
		return ;
	head = *lst;
	while (head != NULL)
	{
		new = head->next;
		ft_lstdelone(head, del);
		head = new;
	}
	*lst = NULL;
}
