/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_program_name.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 12:28:13 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:33:41 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i;

	if (argc < 1)
		return (1);
	i = 0;
	while (argv[0][i])
	{
		write(1, &argv[0][i++], 1);
	}
	write(1, "\n", 1);
}
