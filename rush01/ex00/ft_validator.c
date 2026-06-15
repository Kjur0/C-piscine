/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 13:53:41 by msowinsk          #+#    #+#             */
/*   Updated: 2026/02/01 22:17:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_validator.h"

extern t_bool	ft_check_col_top(const t_grid *grid,
	const t_views *views,
	const t_u8 col)
{
	t_u8	seen;
	t_u8	max;
	t_u8	i;

	i = 0;
	seen = 0;
	max = 0;
	while (i < views->n)
	{
		if (grid->grid[i][col] > max)
		{
			seen++;
			max = grid->grid[i][col];
		}
		i++;
	}
	return (seen == views->views[VIEW_COL_TOP][col]);
}

extern t_bool	ft_check_col_bottom(const t_grid *grid,
	const t_views *views,
	const t_u8 col)
{
	const t_u8	max_i = views->n - 1;
	t_u8		seen;
	t_u8		max;
	t_u8		i;

	i = 0;
	seen = 0;
	max = 0;
	while (i < views->n)
	{
		if (grid->grid[max_i - i][col] > max)
		{
			seen++;
			max = grid->grid[max_i - i][col];
		}
		i++;
	}
	return (seen == views->views[VIEW_COL_BOTTOM][col]);
}

extern t_bool	ft_check_row_left(const t_grid *grid,
	const t_views *views,
	const t_u8 row)
{
	t_u8	seen;
	t_u8	max;
	t_u8	i;

	i = 0;
	seen = 0;
	max = 0;
	while (i < views->n)
	{
		if (grid->grid[row][i] > max)
		{
			seen++;
			max = grid->grid[row][i];
		}
		i++;
	}
	return (seen == views->views[VIEW_ROW_LEFT][row]);
}

extern t_bool	ft_check_row_right(const t_grid *grid,
	const t_views *views,
	const t_u8 row)
{
	const t_u8	max_i = views->n - 1;
	t_u8		seen;
	t_u8		max;
	t_u8		i;

	i = 0;
	seen = 0;
	max = 0;
	while (i < views->n)
	{
		if (grid->grid[row][max_i - i] > max)
		{
			seen++;
			max = grid->grid[row][max_i - i];
		}
		i++;
	}
	return (seen == views->views[VIEW_ROW_RIGHT][row]);
}

extern t_bool	ft_validator(const t_grid *grid, const t_views *views)
{
	int		chk;
	t_u8	i;

	chk = 1;
	i = 0;
	while (i < views->n && chk)
	{
		chk = chk && ft_check_col_top(grid, views, i);
		chk = chk && ft_check_col_bottom(grid, views, i);
		chk = chk && ft_check_row_left(grid, views, i);
		chk = chk && ft_check_row_right(grid, views, i);
		i++;
	}
	return (chk);
}
