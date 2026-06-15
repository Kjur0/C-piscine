/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_merge.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:00:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 11:46:15 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"
#include <stddef.h>

void	ft_sorted_list_merge(t_list **begin_list1, t_list *begin_list2,
	int (*cmp)())
{
	t_list	*cur;
	t_list	*to_insert;

	if (!begin_list1 || !begin_list2)
		return ;
	while (begin_list2)
	{
		to_insert = begin_list2;
		begin_list2 = begin_list2->next;
		to_insert->next = NULL;
		if (!*begin_list1 || (*cmp)(to_insert->data, (*begin_list1)->data) < 0)
		{
			to_insert->next = *begin_list1;
			*begin_list1 = to_insert;
		}
		else
		{
			cur = *begin_list1;
			while (cur->next && (*cmp)(to_insert->data,
				cur->next->data) >= 0)
				cur = cur->next;
			to_insert->next = cur->next;
			cur->next = to_insert;
		}
	}
}
