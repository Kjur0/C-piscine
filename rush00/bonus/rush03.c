/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush03.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:15:18 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 15:02:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

void	rush03(int x, int y)
{
	int	index;

	index = 0;
	while (index < y)
	{
		if (index == 0 || index == y - 1)
			print_line(x, 'A', 'B', 'C');
		else
			print_line(x, 'B', ' ', 'B');
		index++;
	}
}
