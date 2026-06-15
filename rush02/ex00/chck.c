/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chck.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:58:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:37:14 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chck.h"

int	chckdigs(t_string str)
{
	int	i;

	i = 0;
	if (str[0] == '-' && !str[1])
		return (1);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	chckargs(int argc, t_string *argv)
{
	if (argc < 2 || argc > 3)
		return (0);
	if (argc == 2)
		return (chckdigs(argv[1]));
	else
		return (chckdigs(argv[2]));
}
