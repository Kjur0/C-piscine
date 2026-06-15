/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sorted_list_insert.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 00:00:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 11:34:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_sorted_list_insert(t_list **begin_list, void *data, int (*cmp)())
{
	t_list	*new;
	t_list	*cur;

	new = ft_create_elem(data);
	if (!new)
		return ;
	if (!begin_list || !*begin_list || (*cmp)(data, (*begin_list)->data) < 0)
	{
		new->next = *begin_list;
		*begin_list = new;
	}
	else
	{
		cur = *begin_list;
		while (cur->next && (*cmp)(data, cur->next->data) >= 0)
			cur = cur->next;
		new->next = cur->next;
		cur->next = new;
	}
}
