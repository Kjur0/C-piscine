/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_find.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:13:20 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 11:34:51 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)())
{
	t_list	*cur;

	cur = begin_list;
	while (cur)
	{
		if (!((*cmp)(cur->data, data_ref)))
			return (cur);
		cur = cur->next;
	}
	return (0);
}
