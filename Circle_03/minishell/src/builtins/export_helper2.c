/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:12:42 by risattou          #+#    #+#             */
/*   Updated: 2025/07/08 15:13:41 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_valid_export(char **args)
{
	int		i;
	char	*var_name;

	if (args[1] == NULL)
		return (0);
	var_name = args[1];
	if (var_name[0] == '=' || var_name[0] == '+' || ft_isdigit(var_name[0]))
		return (1);
	if (var_name[0] == '-')
		return (1);
	i = 0;
	while (var_name[i] && var_name[i] != '=' && !(var_name[i] == '+'
			&& var_name[i + 1] == '='))
	{
		if (!ft_isalnum(var_name[i]) && var_name[i] != '_')
			return (1);
		i++;
	}
	return (0);
}
