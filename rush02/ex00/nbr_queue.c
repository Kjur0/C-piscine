/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_queue.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:01:40 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:39:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "nbr_queue.h"
#include "nbr_printer.h"

#include <stdlib.h>
#include <unistd.h>

void	queue_add(t_queue *queue, t_string word)
{
	int			i;
	t_string	*words;

	words = malloc(sizeof(t_string *) * (queue->size + 1));
	i = 0;
	while (i < queue->size)
	{
		words[i] = queue->words[i];
		i++;
	}
	words[i] = word;
	free(queue->words);
	queue->words = words;
	queue->size++;
}

t_queue	*queue_init(void)
{
	t_queue	*queue;

	queue = malloc(sizeof(t_queue));
	queue->size = 0;
	queue->words = malloc(0);
	return (queue);
}

void	queue_print(const t_queue *queue)
{
	int	i;

	i = 0;
	while (i < queue->size)
	{
		ft_putstr(queue->words[i]);
		if (i != queue->size - 1)
			write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}

void	queue_destroy(t_queue *queue)
{
	free(queue->words);
	free(queue);
}
