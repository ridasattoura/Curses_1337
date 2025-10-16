/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_helper_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/13 20:49:09 by risattou          #+#    #+#             */
/*   Updated: 2025/03/19 22:11:47 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

static int	handle_single_quotes(char **new, char *str, int *i, int *index)
{
	(*i)++;
	if (str[*i] != '\'' && str[*i])
	{
		new[*index] = ft_strdup_qouts((char *)(str + *i), '\'');
		if (new[*index] == NULL)
		{
			ft_free_qouts(new, *index);
			return (0);
		}
		(*index)++;
	}
	while (str[*i] != '\'' && str[*i])
		(*i)++;
	if (str[*i] == '\'' && str[*i])
	{
		(*i)++;
		return (1);
	}
	ft_free_qouts(new, *index);
	return (0);
}

static int	handle_double_quotes(char **new, char *str, int *i, int *index)
{
	(*i)++;
	if (str[*i] != '\"' && str[*i])
	{
		new[*index] = ft_strdup_qouts((char *)(str + *i), '\"');
		if (new[*index] == NULL)
		{
			ft_free_qouts(new, *index);
			return (0);
		}
		(*index)++;
	}
	while (str[*i] != '\"' && str[*i])
		(*i)++;
	if (str[*i] == '\"' && str[*i])
	{
		(*i)++;
		return (1);
	}
	ft_free_qouts(new, *index);
	return (0);
}

static int	handle_quotes(char **new, char *str, int *i, int *index)
{
	if (((str[*i] == '\'' && str[*i + 1] == '\'') 
			|| (str[*i] == '\"' && str[*i + 1] == '\"')) && str[*i])
		*i += 2;
	if (str[*i] == '\'' && str[*i + 1] != '\'' && str[*i])
	{
		if (!handle_single_quotes(new, str, i, index))
			return (0);
	}
	else if (str[*i] == '\"' && str[*i + 1] != '\"' && str[*i])
	{
		if (!handle_double_quotes(new, str, i, index))
			return (0);
	}
	return (1);
}

int	process_quotes(char **new, char *str, int *i, int *index)
{
	while ((str[*i] == ' ' || str[*i] == '\'' || str[*i] == '\"') && str[*i])
	{
		if (!handle_quotes(new, str, i, index))
			return (0);
		if (str[*i] == '\0')
			break ;
		(*i)++;
	}
	return (1);
}

int	process_non_quotes(char **new, char *str, int *i, int *index)
{
	if (!(str[*i] == ' ' || str[*i] == '\'' || str[*i] == '\"') && str[*i])
	{
		new[*index] = ft_strdup_qouts((char *)(str + *i), ' ');
		if (new[*index] == NULL)
		{
			ft_free_qouts(new, *index);
			return (0);
		}
		(*index)++;
	}
	while (!(str[*i] == ' ' || str[*i] == '\'' || str[*i] == '\"') && str[*i])
		(*i)++;
	return (1);
}
