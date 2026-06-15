/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ops.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:13:20 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:25:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ops.h"

#include "ft_string.h"

#include <unistd.h>

int	add(int a, int b)
{
	ft_putnbr(a + b);
	write(1, "\n", 1);
	return (0);
}

int	subtract(int a, int b)
{
	ft_putnbr(a - b);
	write(1, "\n", 1);
	return (0);
}

int	multiply(int a, int b)
{
	ft_putnbr(a * b);
	write(1, "\n", 1);
	return (0);
}

int	divide(int a, int b)
{
	if (b == 0)
	{
		write(2, "Stop : division by zero\n", 24);
		return (1);
	}
	ft_putnbr(a / b);
	write(1, "\n", 1);
	return (0);
}

int	modulo(int a, int b)
{
	if (b == 0)
	{
		write(2, "Stop : modulo by zero\n", 22);
		return (1);
	}
	ft_putnbr(a % b);
	write(1, "\n", 1);
	return (0);
}
