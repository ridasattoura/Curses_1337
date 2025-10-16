/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/24 14:59:42 by risattou          #+#    #+#             */
/*   Updated: 2025/01/21 12:45:40 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap_bonus.h"

int	ft_split(char const *str, char c, t_list **lst)
{
	int		i;
	t_list	*node;

	i = 0;
	while (str[i])
	{
		while (str[i] == c && str[i])
			i++;
		if (str[i] != c && str[i])
		{
			node = ft_lstnew(ft_atoi((char *)(str + i)));
			if (node == NULL || ft_lstadd_back(lst, node) == 0)
				return (0);
		}
		while (str[i] != c && str[i])
			i++;
	}
	return (1);
}
