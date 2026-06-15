/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 19:59:28 by vtarasov          #+#    #+#             */
/*   Updated: 2026/02/01 22:13:35 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_grid.h"
#include "ft_string.h"
#include "ft_generator.h"

#include <unistd.h>

extern int	main(const int argc, const char **argv)
{
	t_views	*parsed;
	t_grid	*solution;

	if (argc != 2)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	parsed = ft_views_parser(argv[1]);
	if (!parsed)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	solution = ft_generator(parsed);
	if (!solution)
	{
		write(1, "Error\n", 6);
		return (0);
	}
	ft_grid_printer(solution, parsed->n);
	free_grid(solution, parsed->n);
	free_views(parsed);
}
