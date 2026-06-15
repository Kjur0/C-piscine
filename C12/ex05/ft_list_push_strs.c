/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_strs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:48:26 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 20:54:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*prev;
	t_list	*cur;
	int		i;

	if (size <= 0 || !strs)
		return (0);
	cur = ft_create_elem(strs[0]);
	i = 0;
	while (i < size && strs[i])
	{
		prev = cur;
		cur = ft_create_elem(strs[i++]);
		cur->next = prev;
	}
	return (cur);
}
