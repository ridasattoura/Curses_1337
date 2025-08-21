/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wildcard_utils2_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mohchaib <mohchaib@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/05 06:00:18 by mohchaib          #+#    #+#             */
/*   Updated: 2025/07/09 16:54:58 by mohchaib         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell_bonus.h"

void	inc_two(int *i, int *j)
{
	(*j)++;
	(*i)++;
}

void	assign_stuff(int *p, int *last_astric, int *match, int f)
{
	*last_astric = *p;
	*match = f;
	(*p)++;
}

void	move_c(int *p, int *f, int *match, int last_astric)
{
	(*match)++;
	*p = last_astric + 1;
	*f = *match;
}

bool	wildcard_match(char *pattern, const char *filename)
{
	int	f;
	int	p;
	int	last_astric;
	int	match;

	f = 0;
	p = 0;
	last_astric = -1;
	match = 0;
	while (filename[f])
	{
		if (pattern[p] && pattern[p] == filename[f])
			inc_two(&p, &f);
		else if (pattern[p] == '*')
			assign_stuff(&p, &last_astric, &match, f);
		else if (last_astric != -1)
			move_c(&p, &f, &match, last_astric);
		else
			return (false);
	}
	while (pattern[p] == '*')
		p++;
	return (pattern[p] == '\0');
}
