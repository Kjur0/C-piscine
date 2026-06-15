/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_merge.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 18:26:02 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 21:06:50 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*cur;

	if (!begin_list1 || !*begin_list1)
		*begin_list1 = begin_list2;
	else
	{
		cur = *begin_list1;
		while (cur->next)
			cur = cur->next;
		cur->next = begin_list2;
	}
}
