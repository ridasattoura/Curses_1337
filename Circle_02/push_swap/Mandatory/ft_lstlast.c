/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/07 00:11:57 by risattou          #+#    #+#             */
/*   Updated: 2025/01/28 09:44:25 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	ft_lstlast(t_list **lst)
{
	t_list	*tmp1;

	if (!(*lst))
		return ;
	tmp1 = *lst;
	while (tmp1->next->next != NULL)
		tmp1 = tmp1->next;
	tmp1->next = NULL;
}
