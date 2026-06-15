/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_used.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 21:00:14 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:19:40 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_used.h"

#include <stdlib.h>

static t_used	*malloc_used(const t_u8 n)
{
	t_used	*used;
	t_u8	i;

	used = malloc(sizeof(t_used));
	used->col = malloc(sizeof(t_bool *) * n);
	i = 0;
	while (i < n)
	{
		used->col[i] = malloc(sizeof(t_bool) * n);
		i++;
	}
	used->row = malloc(sizeof(t_bool *) * n);
	i = 0;
	while (i < n)
	{
		used->row[i] = malloc(sizeof(t_bool) * n);
		i++;
	}
	return (used);
}

extern t_used	*init_used(const t_u8 n)
{
	t_used	*used;
	t_u8	i;
	t_u8	j;

	used = malloc_used(n);
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			used->col[i][j] = FALSE;
			used->row[i][j] = FALSE;
			j++;
		}
		i++;
	}
	return (used);
}

extern void	free_used(t_used *used, const t_u8 n)
{
	t_u8	i;

	i = 0;
	while (i < n)
	{
		free(used->row[i]);
		i++;
	}
	free(used->row);
	i = 0;
	while (i < n)
	{
		free(used->col[i]);
		i++;
	}
	free(used->col);
	free(used);
}
