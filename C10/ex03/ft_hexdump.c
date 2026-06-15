/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexdump.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:50:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/13 00:03:43 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_hexdump.h"

#include "ft_print.h"

// open, close
#include <fcntl.h>
// read
#include <unistd.h>

#define BUF_SIZE	4096

static void	process_buffer(unsigned char *buf, int n, t_hexdump *hd)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (i + 16 <= n)
		{
			if (hd->is_c)
				print_hex_line(buf + i, 16, hd->offset);
			else
				print_hex_line_default(buf + i, 16, hd->offset);
			hd->offset += 16;
			i += 16;
		}
		else
		{
			if (hd->is_c)
				print_hex_line(buf + i, n - i, hd->offset);
			else
				print_hex_line_default(buf + i, n - i, hd->offset);
			hd->offset += (n - i);
			i = n;
		}
	}
}

int	hexdump_stdin(t_hexdump *hd)
{
	unsigned char	buf[BUF_SIZE];
	int				n;

	while (1)
	{
		n = read(0, buf, BUF_SIZE);
		if (n < 0)
			return (1);
		if (n == 0)
			break ;
		process_buffer(buf, n, hd);
	}
	return (0);
}

int	hexdump_file(char *filename, t_hexdump *hd)
{
	int				fd;
	unsigned char	buf[BUF_SIZE];
	int				n;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (1);
	while (1)
	{
		n = read(fd, buf, BUF_SIZE);
		if (n < 0)
		{
			close(fd);
			return (1);
		}
		if (n == 0)
			break ;
		process_buffer(buf, n, hd);
	}
	close(fd);
	return (0);
}
