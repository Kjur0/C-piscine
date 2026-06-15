/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_remove_if.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:19:35 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 21:05:32 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)(),
			void (*free_fct)(void *))
{
	t_list	*cur;
	t_list	*tmp;

	cur = *begin_list;
	while (cur)
	{
		if (!(*cmp)(cur->data, data_ref))
		{
			tmp = cur->next;
			cur->next = cur->next->next;
			free_fct(tmp->data);
			free(tmp);
		}
		cur = cur->next;
	}
	cur = *begin_list;
	if (cur && !(*cmp)(cur->data, data_ref))
	{
		*begin_list = cur->next;
		(*free_fct)(cur->data);
		free(cur);
	}
}
