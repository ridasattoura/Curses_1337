/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: risattou <risattou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 10:57:23 by risattou          #+#    #+#             */
/*   Updated: 2024/07/09 23:07:33 by risattou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printsolution(int *arr)
{
	int		i;
	char	c;

	i = 0;
	while (i < 10)
	{
		c = arr[i] + 48;
		write(1, &c, 1);
		i++;
	}
	write(1, "\n", 1);
}

int	safe_position(int *arr, int depth)
{
	int	i;

	i = depth;
	while (i > 0)
	{
		if ((arr[depth] == arr[depth - i]) || ((arr[depth]
					- depth) == (arr[depth - i] - (depth - i))) || ((arr[depth]
					+ depth) == (arr[depth - i] + (depth - i))))
			return (0);
		i--;
	}
	return (1);
}

void	solution(int *arr, int depth, int *i)
{
	int	j;

	if (depth == 10)
	{
		printsolution(arr);
		(*i)++;
	}
	j = 0;
	while (depth < 10 && j < 10)
	{
		arr[depth] = j;
		if (safe_position(arr, depth))
			solution(arr, (depth + 1), i);
		j++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	arr[10];
	int	i;
	int	depth;

	depth = 0;
	i = 0;
	solution(arr, depth, &i);
	return (i);
}
