/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do-op.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:17:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:22:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"
#include "ops.h"

#include <unistd.h>

int	main(int argc, char **argv)
{
	int		(*op_array[5])(int, int);
	char	*operators;
	int		i;

	if (argc != 4)
		return (0);
	operators = "+-*/%";
	op_array[0] = add;
	op_array[1] = subtract;
	op_array[2] = multiply;
	op_array[3] = divide;
	op_array[4] = modulo;
	i = 0;
	while (i < 5 && argv[2][0] != operators[i])
		i++;
	if (i == 5)
	{
		write(1, "0\n", 2);
		return (0);
	}
	return (op_array[i](ft_atoi(argv[1]), ft_atoi(argv[3])));
}
