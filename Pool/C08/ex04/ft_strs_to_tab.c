/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*    ft_strs_to_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/15 07:18:16 by risattou          #+#    #+#             */
/*   Updated: 2024/07/16 10:37:40 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strdup(char *src)
{
	char	*new_src;
	int		i;

	new_src = (char *)malloc((ft_strlen(src) + 1) * sizeof(char));
	if (new_src == NULL)
		return (NULL);
	i = 0;
	while (src[i] != '\0')
	{
		new_src[i] = src[i];
		i++;
	}
	new_src[i] = '\0';
	return (new_src);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*new;
	int					i;

	new = malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (new == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		new[i].size = ft_strlen(av[i]);
		new[i].str = av[i];
		new[i].copy = ft_strdup(av[i]);
		i++;
	}
	new[i].str = NULL;
	new[i].size = 0;
	new[i].copy = NULL;
	return (new);
}
