/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:09:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/10 19:39:17 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"

// open, close
#include <fcntl.h>
// read, write
#include <unistd.h>

void	errorln(const char *str)
{
	while (*str)
		write(2, str++, 1);
	write(2, "\n", 1);
}

void	println(const char *str)
{
	while (*str)
		write(1, str++, 1);
	write(1, "\n", 1);
}

#define BUF_SIZE 1024

int	print_file(const char *filename)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		errorln("Cannot read file.");
		return (1);
	}
	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, BUF_SIZE);
	}
	close(fd);
	if (bytes_read < 0)
	{
		errorln("Cannot read file.");
		return (1);
	}
	return (0);
}
