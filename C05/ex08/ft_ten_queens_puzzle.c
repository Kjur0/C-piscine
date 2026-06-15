/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ten_queens_puzzle.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 11:36:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/09 11:48:43 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

static int	is_safe(int *pos, int col, int row)
{
	int	i;
	int	d;

	i = 0;
	while (i < col)
	{
		d = col - i;
		if (pos[i] == row)
			return (0);
		if (row - pos[i] == d)
			return (0);
		if (pos[i] - row == d)
			return (0);
		i++;
	}
	return (1);
}

static void	print_solution(int *pos)
{
	char	buf[11];
	int		i;

	i = 0;
	while (i < 10)
	{
		buf[i] = pos[i] + '0';
		i++;
	}
	buf[10] = '\n';
	write(1, buf, 11);
}

static void	solve(int *pos, int col, int *count)
{
	int	row;

	if (col == 10)
	{
		print_solution(pos);
		*count = *count + 1;
		return ;
	}
	row = 0;
	while (row < 10)
	{
		if (is_safe(pos, col, row))
		{
			pos[col] = row;
			solve(pos, col + 1, count);
		}
		row++;
	}
}

int	ft_ten_queens_puzzle(void)
{
	int	pos[10];
	int	count;

	count = 0;
	solve(pos, 0, &count);
	return (count);
}
