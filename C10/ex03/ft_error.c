/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:50:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 15:57:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_error.h"

#include "ft_string.h"

// strerror
#include <string.h>
// errno
#include <errno.h>
// basename
#include <libgen.h>
// write
#include <unistd.h>

void	print_error(char *prog, char *file)
{
	char	*base;

	base = basename(file);
	write(2, prog, ft_strlen(prog));
	write(2, ": ", 2);
	write(2, base, ft_strlen(base));
	write(2, ": ", 2);
	write(2, strerror(errno), ft_strlen(strerror(errno)));
	write(2, "\n", 1);
}
