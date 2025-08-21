/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envp_utils1_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 12:05:21 by risattou          #+#    #+#             */
/*   Updated: 2025/07/09 16:53:21 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	free_matrix_(char **matrix, int i)
{
	while (i >= 0)
		free(matrix[i--]);
	free(matrix);
}

char	*copy(char *new, char *s1, char *s2)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s1[i])
	{
		new[i] = s1[i];
		i++;
	}
	new[i] = '=';
	i++;
	while (s2[j])
	{
		new[i] = s2[j];
		j++;
		i++;
	}
	return (new);
}

char	*ft_strjoin_(char *s1, char *s2)
{
	int		size;
	char	*new;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	size = ft_strlen(s1) + ft_strlen(s2) + 1;
	new = malloc(size + 1);
	if (!new)
		return (NULL);
	new[size] = 0;
	return (copy(new, (char *)s1, (char *)s2));
}

void	free_matrix(char **matrix)
{
	int	i;

	i = 0;
	if (!matrix)
		return ;
	while (matrix[i])
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
}

void	ft_update_envp(t_shell *shell, int flag)
{
	int	i;

	i = 0;
	if (shell->env != NULL && flag == 1)
	{
		while (shell->env[i] != NULL)
		{
			free(shell->env[i]);
			i++;
		}
		free(shell->env);
	}
	shell->env = NULL;
	shell->env = get_env(shell->envp_list);
}
