/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_sort.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:43:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 21:09:20 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_swap(t_list *list)
{
	void	*tmp;

	tmp = list->data;
	list->data = list->next->data;
	list->next->data = tmp;
}

// bubble sort
void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	t_list	*a;
	t_list	*b;

	if (!begin_list || !*begin_list)
		return ;
	a = *begin_list;
	while (a)
	{
		b = *begin_list;
		while (b->next)
		{
			if ((*cmp)(b->data, b->next->data) > 0)
				ft_list_swap(b);
		}
		b = b->next;
	}
}
