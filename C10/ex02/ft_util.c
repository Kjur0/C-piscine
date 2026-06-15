/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_util.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 23:35:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:37:00 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_util.h"

// malloc, free
#include <stdlib.h>
// read
#include <unistd.h>
// ft_string functions
#include "ft_string.h"
// ft_log
#include "ft_print.h"

int	get_tail_c(char *out, int fd, int count)
{
	char		*buf;
	int			bytes_read;

	buf = malloc(count + 1);
	bytes_read = read(fd, buf, count);
	while (bytes_read > 0)
	{
		if (bytes_read < count)
		{
			if (out[0])
				ft_strshft_left(out, bytes_read, count, buf);
			else
			{
				ft_strcpy(out, buf, bytes_read);
				out[bytes_read] = 0;
			}
		}
		else
			ft_strcpy(out, buf, count);
		bytes_read = read(fd, buf, count);
	}
	free(buf);
	if (bytes_read < 0)
		return (0);
	return (1);
}

void	ft_print_header(char *filename)
{
	ft_log("==> ");
	ft_log(filename);
	ft_log(" <==\n");
}
