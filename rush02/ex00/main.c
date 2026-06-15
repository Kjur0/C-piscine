/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 15:05:49 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:42:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "chck.h"
#include "errors.h"
#include "dict.h"
#include "parser.h"
#include "nbr_printer.h"
#include "nbr_queue.h"
#include "reader.h"

int	main(int argc, char **argv)
{
	t_dict	*dict;
	t_queue	*queue;

	if (!chckargs(argc, argv))
		return (!error());
	if (argc == 2)
		dict = parser("./numbers.dict");
	else
		dict = parser(argv[1]);
	if (!dict)
		return (!error_dict());
	if (argv[argc - 1][0] != '-')
	{
		queue = queue_init();
		printer(queue, dict, argv[argc - 1]);
		queue_print(queue);
		queue_destroy(queue);
	}
	else
		while (reader(dict))
			;
	dict_destroy(dict);
}
