/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_factorial.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 16:13:17 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/07 16:17:03 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_iterative_factorial(int nb)
{
	int	out;
	int	i;

	if (nb < 0)
		return (0);
	out = 1;
	i = 1;
	while (i <= nb)
	{
		out *= i;
		i++;
	}
	return (out);
}
