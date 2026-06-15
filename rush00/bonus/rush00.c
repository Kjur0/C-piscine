/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush00.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:05:57 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 15:02:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

void	rush00(int x, int y)
{
	int	index;

	index = 0;
	while (index < y)
	{
		if (index == 0 || index == y - 1)
			print_line(x, 'o', '-', 'o');
		else
			print_line(x, '|', ' ', '|');
		index++;
	}
}
