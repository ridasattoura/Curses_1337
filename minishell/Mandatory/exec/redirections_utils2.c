/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirections_utils2.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/09 07:07:00 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/20 16:33:24 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ambiguous_handle(t_token *list)
{
	if (check_ambiguous(list) == -1)
	{
		printf(ERR12);
		exit(1);
	}
}

void	check_string(t_token *temp, int *fd)
{
	if (ft_strlen(temp->value) == 0)
		return (printf(ERR12), exit(1));
	(*fd) = open(temp->value, O_RDONLY);
}
