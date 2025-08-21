/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_builtins_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 10:40:31 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:09 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

int	one(char **av)
{
	if ((ft_strncmp(av[0], "env", ft_strlen("env")) == 0
			&& ft_strlen(av[0]) == ft_strlen("env")))
	{
		if (av[1] == NULL)
			return (0);
	}
	return (-1);
}

int	two(char **av)
{
	if ((ft_strncmp(av[0], "export", ft_strlen("export")) == 0
			&& ft_strlen(av[0]) == ft_strlen("export") && av[1] == NULL)
		|| (ft_strncmp(av[0], "pwd", ft_strlen("pwd")) == 0
			&& ft_strlen(av[0]) == ft_strlen("pwd")))
		return (0);
	return (-1);
}

int	ft_should_fork(char **av)
{
	if (!av)
		return (-1);
	if (ft_strncmp(av[0], "echo", ft_strlen("echo")) == 0
		&& ft_strlen(av[0]) == ft_strlen("echo"))
		return (0);
	if (!one(av))
		return (0);
	if (!two(av))
		return (0);
	return (-1);
}
