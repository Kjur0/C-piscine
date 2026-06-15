/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_grid.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 20:13:38 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:17:22 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_GRID_H
# define FT_GRID_H

# include "ft_types.h"

enum		e_views
{
	VIEW_COL_TOP,
	VIEW_COL_BOTTOM,
	VIEW_ROW_LEFT,
	VIEW_ROW_RIGHT
};
typedef struct s_views
{
	t_u8	**views;
	t_u8	n;
}	t_views;
typedef struct s_grid
{
	t_u8	**grid;
}	t_grid;

extern t_grid	*malloc_grid(const t_u8 n);
extern t_views	*malloc_views(const t_u8 n);
extern void		free_grid(t_grid *grid, const t_u8 n);
extern void		free_views(t_views *views);
extern void		ft_grid_printer(const t_grid *grid, const t_u8 n);

#endif