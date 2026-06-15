/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: twloskow <twloskow@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:06:54 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 23:10:27 by twloskow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"

#include <unistd.h>

void	*error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

void	*error_dict(void)
{
	write(2, "Dict Error\n", 11);
	return (0);
}
