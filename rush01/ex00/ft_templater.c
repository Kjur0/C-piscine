/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_templater.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:06:12 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:21:21 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_templater.h"

static void	template_col_top(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int i)
{
	const t_u8	col = i % views->n;
	const t_u8	val = views->views[VIEW_COL_TOP][col];
	t_u8		j;

	if (val != 1 && val != views->n)
		return ;
	if (val == 1)
	{
		grid->grid[0][col] = views->n;
		used->col[col][views->n - 1] = 1;
		used->row[0][views->n - 1] = 1;
		return ;
	}
	j = 0;
	while (j < views->n)
	{
		grid->grid[j][col] = j + 1;
		used->col[col][j] = 1;
		used->row[j][j] = 1;
		j++;
	}
}

static void	template_col_bottom(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int i)
{
	const t_u8	col = i % views->n;
	const t_u8	val = views->views[VIEW_COL_BOTTOM][col];
	const t_u8	max_row = views->n - 1;
	t_u8		j;

	if (val != 1 && val != views->n)
		return ;
	if (val == 1)
	{
		grid->grid[max_row][col] = views->n;
		used->col[col][views->n - 1] = 1;
		used->row[max_row][views->n - 1] = 1;
		return ;
	}
	j = 0;
	while (j < views->n)
	{
		grid->grid[max_row - j][col] = j + 1;
		used->col[col][j] = 1;
		used->row[max_row - j][j] = 1;
		j++;
	}
}

static void	template_row_left(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int i)
{
	const t_u8	row = i % views->n;
	const t_u8	val = views->views[VIEW_ROW_LEFT][row];
	t_u8		j;

	if (val != 1 && val != views->n)
		return ;
	if (val == 1)
	{
		grid->grid[row][0] = views->n;
		used->col[0][views->n - 1] = 1;
		used->row[row][views->n - 1] = 1;
		return ;
	}
	j = 0;
	while (j < views->n)
	{
		grid->grid[row][j] = j + 1;
		used->col[j][j] = 1;
		used->row[row][j] = 1;
		j++;
	}
}

static void	template_row_right(t_grid *grid,
	const t_views *views,
	t_used *used,
	const int i)
{
	const t_u8	row = i % views->n;
	const t_u8	val = views->views[VIEW_ROW_RIGHT][row];
	const t_u8	max_col = views->n - 1;
	t_u8		j;

	if (val != 1 && val != views->n)
		return ;
	if (val == 1)
	{
		grid->grid[row][max_col] = views->n;
		used->col[max_col][views->n - 1] = 1;
		used->row[row][views->n - 1] = 1;
		return ;
	}
	j = 0;
	while (j < views->n)
	{
		grid->grid[row][max_col - j] = j + 1;
		used->col[max_col - j][j] = 1;
		used->row[row][j] = 1;
		j++;
	}
}

extern t_grid	*ft_templater(const t_views *views, t_used *used)
{
	int		i;
	t_grid	*out;

	out = malloc_grid(views->n);
	i = 0;
	while (i < views->n * views->n)
	{
		out->grid[i / views->n][i % views->n] = 0;
		i++;
	}
	i = 0;
	while (i < 4 * views->n)
	{
		if (i / views->n == VIEW_COL_TOP)
			template_col_top(out, views, used, i);
		else if (i / views->n == VIEW_COL_BOTTOM)
			template_col_bottom(out, views, used, i);
		else if (i / views->n == VIEW_ROW_LEFT)
			template_row_left(out, views, used, i);
		else if (i / views->n == VIEW_ROW_RIGHT)
			template_row_right(out, views, used, i);
		i++;
	}
	return (out);
}
