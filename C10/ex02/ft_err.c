/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:52:46 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:36:53 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

// errno
#include <errno.h>
// strerror
#include <string.h>
// basename
#include <libgen.h>

int	ft_err(char *prog, char *file)
{
	char	*err_msg;

	err_msg = strerror(errno);
	ft_error(basename(prog));
	ft_error(": cannot open '");
	ft_error(file);
	ft_error("' for reading: ");
	ft_error(err_msg);
	ft_error("\n");
	return (1);
}

int	ft_nbrerr(char *prog, char *nbr)
{
	ft_error(basename(prog));
	ft_error(": invalid number of bytes: `");
	ft_error(nbr);
	ft_error("`\n");
	return (1);
}
