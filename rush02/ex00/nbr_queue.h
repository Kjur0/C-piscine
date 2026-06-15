/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_queue.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 23:02:53 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:19:09 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_QUEUE_H
# define NBR_QUEUE_H

# include "ft_string.h"

typedef struct s_queue
{
	t_string	*words;
	int			size;
}	t_queue;

void	queue_add(t_queue *queue, t_string word);
t_queue	*queue_init(void);
void	queue_print(const t_queue *queue);
void	queue_destroy(t_queue *queue);

#endif
