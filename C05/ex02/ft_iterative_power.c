/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:18:11 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/07 16:20:28 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_power(int nb, int power)
{
	int	out;
	int	i;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	out = nb;
	i = 1;
	while (i < power)
	{
		out *= nb;
		i++;
	}
	return (out);
}
