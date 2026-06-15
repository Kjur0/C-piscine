/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush04.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:06:57 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 15:02:49 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

void	rush04(int x, int y)
{
	int	index;

	index = 0;
	while (index < y)
	{
		if (index == 0)
			print_line(x, 'A', 'B', 'C');
		else if (index == y - 1)
			print_line(x, 'C', 'B', 'A');
		else
			print_line(x, 'B', ' ', 'B');
		index++;
	}
}
