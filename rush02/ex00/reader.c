/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 22:47:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:42:57 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr_printer.h"
#include "chck.h"

#include <stdlib.h>
#include <unistd.h>

t_string	read_input(void)
{
	int			i;
	char		buff[1];
	t_string	out;
	t_string	tmp;

	out = malloc(1);
	out[0] = 0;
	i = 1;
	while (read(0, buff, 1) > 0)
	{
		if (*buff > '9' || *buff < '0')
			break ;
		tmp = malloc(i + 1);
		ft_strcpy(tmp, out);
		tmp[i - 1] = *buff;
		tmp[i] = 0;
		free(out);
		out = tmp;
		i++;
	}
	return (out);
}

int	reader(const t_dict *dict)
{
	t_string	out;
	t_queue		*queue;
	int			chck;

	queue = queue_init();
	out = read_input();
	chck = chckdigs(out);
	if (chck)
		printer(queue, dict, out);
	queue_print(queue);
	queue_destroy(queue);
	free(out);
	return (chck);
}
