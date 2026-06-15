/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nbr_printer.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 20:38:45 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:32:19 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NBR_PRINTER_H
# define NBR_PRINTER_H

# include "dict.h"
# include "ft_string.h"
# include "nbr_queue.h"

void	ft_putstr(const t_string str);
void	printer(t_queue *queue, const t_dict *dict, t_string nbr);

#endif