/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 20:09:23 by ldubok            #+#    #+#             */
/*   Updated: 2026/01/24 07:06:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"
#include "./ft_putchar.h"

void	print_line(int length, char start, char middle, char end)
{
	int	i;

	ft_putchar(start);
	i = 1;
	while (i < length)
	{
		if (i == length - 1)
			ft_putchar(end);
		else
			ft_putchar(middle);
		i++;
	}
	ft_putchar('\n');
}
