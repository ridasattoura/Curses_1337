/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utiles_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 05:09:37 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 22:14:06 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	ft_free(char **array)
{
	int	i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		i++;
	}
	free(array);
}

void	ft_close(t_files files, char **array, char **cmnds)
{
	if (array)
		ft_free(array);
	if (cmnds)
		ft_free(cmnds);
	if (files.fdin != -1)
		close(files.fdin);
	if (files.fd[0] != -1)
		close(files.fd[0]);
	if (files.fd[1] != -1)
		close(files.fd[1]);
	if (files.fdout != -1)
		close(files.fdout);
}
