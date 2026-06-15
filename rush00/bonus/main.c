/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:12:37 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/24 15:09:29 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"
#include "./ft_atoi.h"

#define EXIT_FAIL 1
#define EXIT_SUCCESS 0

int	main(int argc, char **argv)
{
	char	mode;

	if (argc != 4)
		return (EXIT_FAIL);
	mode = argv[1][0];
	if (mode == '0')
		rush00(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (mode == '1')
		rush01(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (mode == '2')
		rush02(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (mode == '3')
		rush03(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else if (mode == '4')
		rush04(ft_atoi(argv[2]), ft_atoi(argv[3]));
	else
		return (EXIT_FAIL);
	return (EXIT_SUCCESS);
}
