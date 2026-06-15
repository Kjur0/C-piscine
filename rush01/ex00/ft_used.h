/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_used.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/01 20:59:23 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:15:42 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_USED_H
# define FT_USED_H

# include "ft_types.h"

typedef struct s_used
{
	t_bool	**col;
	t_bool	**row;
}	t_used;

extern t_used	*init_used(const t_u8 n);
extern void		free_used(t_used *used, const t_u8 n);

#endif