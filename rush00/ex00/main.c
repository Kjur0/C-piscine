/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 19:12:37 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/24 14:57:05 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./rush.h"

#define EXIT_FAIL 1
#define EXIT_SUCCESS 0

int	main(void)
{
	rush(4, 4);
	return (EXIT_SUCCESS);
}
