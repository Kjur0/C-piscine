/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:05:57 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 15:02:42 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

void	rush02(int x, int y)
{
	int	index;

	index = 0;
	while (index < y)
	{
		if (index == 0)
			print_line(x, 'A', 'B', 'A');
		else if (index == y - 1)
			print_line(x, 'C', 'B', 'C');
		else
			print_line(x, 'B', ' ', 'B');
		index++;
	}
}
