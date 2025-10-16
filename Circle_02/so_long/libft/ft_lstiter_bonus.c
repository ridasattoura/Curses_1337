/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:11:52 by risattou          #+#    #+#             */
/*   Updated: 2024/11/07 00:11:53 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*head;
	t_list	*new;

	if (!lst || !f)
		return ;
	head = lst;
	while (head != NULL)
	{
		new = head;
		f(new->content);
		head = head->next;
	}
}
