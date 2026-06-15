/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/24 15:10:33 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/24 15:11:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./ft_atoi.h"

int	ft_atoi(char *str)
{
	int	out;
	int	neg;
	int	i;

	out = 0;
	neg = 1;
	i = 0;
	if (str[i] == '-')
	{
		neg = -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		out *= 10;
		out += str[i] - '0';
		i++;
	}
	return (neg * out);
}
