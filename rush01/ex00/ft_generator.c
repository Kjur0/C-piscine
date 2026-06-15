/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_generator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 16:03:30 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:23:17 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_generator.h"

#include "ft_used.h"
#include "ft_validator.h"
#include "ft_templater.h"

static t_bool	ft_fill_grid(t_grid *grid,
					const t_views *views,
					t_used *used,
					const int pos);

static t_bool	ft_loop_fill_grid(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int pos)
{
	const t_u8	row = pos / views->n;
	const t_u8	col = pos % views->n;
	t_u8		num;

	num = 1;
	while (num <= views->n)
	{
		if (!used->col[col][num - 1] && !used->row[row][num - 1])
		{
			used->col[col][num - 1] = 1;
			used->row[row][num - 1] = 1;
			grid->grid[row][col] = num;
			if (ft_fill_grid(grid, views, used, pos + 1))
				return (1);
			used->col[col][num - 1] = 0;
			used->row[row][num - 1] = 0;
			grid->grid[row][col] = 0;
		}
		num++;
	}
	return (0);
}

static t_bool	ft_fill_grid(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int pos)
{
	const t_u8	row = pos / views->n;
	const t_u8	col = pos % views->n;

	if (pos == views->n * views->n)
		return (ft_validator(grid, views));
	if (row > 0 && col == 0)
		if (!ft_check_row_left(grid, views, row - 1)
			|| !ft_check_row_right(grid, views, row - 1))
			return (0);
	if (col > 0 && row == views->n - 1)
		if (!ft_check_col_top(grid, views, col - 1)
			|| !ft_check_col_bottom(grid, views, col - 1))
			return (0);
	if (grid->grid[row][col] != 0)
		return (ft_fill_grid(grid, views, used, pos + 1));
	return (ft_loop_fill_grid(grid, views, used, pos));
}

extern t_grid	*ft_generator(const t_views *views)
{
	t_grid	*out;
	t_used	*used;

	used = init_used(views->n);
	out = ft_templater(views, used);
	if (ft_fill_grid(out, views, used, 0))
	{
		free_used(used, views->n);
		return (out);
	}
	free_used(used, views->n);
	free_grid(out, views->n);
	return (0);
}
