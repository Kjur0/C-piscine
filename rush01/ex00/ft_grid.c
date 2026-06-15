/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:26:24 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:22:23 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_grid.h"

#include <stdlib.h>
#include <unistd.h>

extern t_grid	*malloc_grid(const t_u8 n)
{
	t_grid	*grid;
	t_u8	i;

	grid = malloc(sizeof(t_grid));
	grid->grid = malloc(sizeof(t_u8 *) * n);
	i = 0;
	while (i < n)
	{
		grid->grid[i] = malloc(sizeof(t_u8) * n);
		i++;
	}
	return (grid);
}

extern t_views	*malloc_views(const t_u8 n)
{
	t_views	*views;
	int		i;

	views = malloc(sizeof(t_views));
	views->views = malloc(sizeof(t_u8 *) * 4);
	i = 0;
	while (i < 4)
	{
		views->views[i] = malloc(sizeof(t_u8) * n);
		i++;
	}
	return (views);
}

extern void	free_grid(t_grid *grid, const t_u8 n)
{
	t_u8	i;

	i = 0;
	while (i < n)
	{
		free(grid->grid[i]);
		i++;
	}
	free(grid->grid);
	free(grid);
}

extern void	free_views(t_views *views)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(views->views[i]);
		i++;
	}
	free(views->views);
	free(views);
}

extern void	ft_grid_printer(const t_grid *grid, const t_u8 n)
{
	t_u8	i;
	t_u8	j;
	char	c;

	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n)
		{
			c = grid->grid[i][j] + '0';
			write(1, &c, 1);
			if (j < n - 1)
				write(1, " ", 1);
			j++;
		}
		write(1, "\n", 1);
		i++;
	}
}
