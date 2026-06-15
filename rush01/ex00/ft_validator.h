/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validator.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 15:07:54 by msowinsk          #+#    #+#             */
/*   Updated: 2026/02/01 22:18:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VALIDATOR_H
# define FT_VALIDATOR_H

# include "ft_grid.h"

extern t_bool	ft_check_col_top(const t_grid *grid,
					const t_views *views,
					const t_u8 col);
extern t_bool	ft_check_col_bottom(const t_grid *grid,
					const t_views *views,
					const t_u8 col);
extern t_bool	ft_check_row_left(const t_grid *grid,
					const t_views *views,
					const t_u8 row);
extern t_bool	ft_check_row_right(const t_grid *grid,
					const t_views *views,
					const t_u8 row);
extern t_bool	ft_validator(const t_grid *grid, const t_views *views);
#endif
