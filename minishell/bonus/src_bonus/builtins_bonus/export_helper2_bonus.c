/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export_helper2_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/08 15:12:42 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:05 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

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

void	print_exp_list(t_env *envp_list)
{
	t_env	*head;

	head = envp_list;
	while (head != NULL)
	{
		printf("declare -x %s", head->variable);
		if (head->is_export == 1 && head->value != NULL)
		{
			printf("=");
			printf("\"%s\"", head->value);
		}
		printf("\n");
		head = head->next;
	}
}
