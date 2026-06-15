/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:05:26 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/10 18:48:50 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		errorln("File name missing.");
		return (1);
	}
	if (argc > 2)
	{
		errorln("Too many arguments.");
		return (1);
	}
	return (print_file(argv[1]));
}
