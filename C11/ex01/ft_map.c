/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:07:11 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:31:24 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_map(int *tab, int length, int (*f)(int))
{
	int	i;
	int	*out;

	i = 0;
	out = malloc(sizeof(int) * length);
	while (i < length)
	{
		out[i] = f(tab[i]);
		i++;
	}
	return (out);
}
