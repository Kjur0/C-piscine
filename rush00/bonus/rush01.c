/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush01.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:06:57 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 15:02:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

void	rush01(int x, int y)
{
	int	index;

	index = 0;
	while (index < y)
	{
		if (index == 0)
			print_line(x, '/', '*', '\\');
		else if (index == y - 1)
			print_line(x, '\\', '*', '/');
		else
			print_line(x, '*', ' ', '*');
		index++;
	}
}
