/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:10:33 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:24:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <unistd.h>

void	ft_putnbr(int nb)
{
	char	c;

	if (nb < 0)
	{
		write(1, "-", 1);
		if (nb < -9)
			ft_putnbr(nb / -10);
		c = '0' - nb % 10;
	}
	if (nb > 9)
		ft_putnbr(nb / 10);
	if (nb >= 0)
		c = '0' + nb % 10;
	write(1, &c, 1);
}

int	ft_atoi(char *str)
{
	int	out;
	int	neg;
	int	i;

	out = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || str[i] == '\t' || str[i] == '\n' || str[i] == '\v'
		|| str[i] == '\f' || str[i] == '\r')
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		out *= 10;
		out += str[i] - '0';
		i++;
	}
	return (neg * out);
}
