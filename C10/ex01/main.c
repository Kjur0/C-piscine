/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:05:26 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 19:27:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		return (print_stdin(argv[0]));
	}
	if (argc == 2 && argv[1][0] == '-' && !argv[1][1])
	{
		return (print_stdin(argv[0]));
	}
	return (cat(argc, argv));
}
