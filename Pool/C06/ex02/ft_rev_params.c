/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/07 18:32:09 by risattou          #+#    #+#             */
/*   Updated: 2024/07/07 19:29:25 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return ;
}

int	main(int argc, char *argv[])
{
	if (argc > 1)
	{
		while (argc - 1 > 0)
		{
			ft_putstr(argv[argc - 1]);
			ft_putstr("\n");
			argc--;
		}
	}
	return (0);
}
