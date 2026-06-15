/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_combn.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 14:33:51 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/22 18:35:41 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	build(char *buffer, int position, int start, int n)
{
	int	digit;

	digit = start;
	while (digit <= 10 - (n - position))
	{
		buffer[position] = '0' + digit;
		if (position == n - 1)
		{
			write(1, buffer, n);
			if (buffer[0] <= '9' - n)
				write(1, ", ", 2);
		}
		else
			build(buffer, position + 1, digit + 1, n);
		digit++;
	}
}

void	ft_print_combn(int n)
{
	char	buffer[10];

	build(buffer, 0, 0, n);
}
