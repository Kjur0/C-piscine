/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 17:09:03 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 22:25:48 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cat.h"

#include "ft_string.h"

// basename
#include <libgen.h>
// errno
#include <errno.h>
// open, close
#include <fcntl.h>
// write, read
#include <unistd.h>
// strerror
#include <string.h>

void	print_error(char *program, char *filename)
{
	char	*err_msg;

	err_msg = strerror(errno);
	write(2, basename(program), ft_strlen(basename(program)));
	write(2, ": ", 2);
	write(2, filename, ft_strlen(filename));
	write(2, ": ", 2);
	write(2, err_msg, ft_strlen(err_msg));
	write(2, "\n", 1);
}

int	print_stdin(char *prog)
{
	int		bytes_read;
	char	buf[1];

	bytes_read = read(0, buf, 1);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(0, buf, 1);
	}
	if (bytes_read < 0)
	{
		print_error(prog, "stdin");
		return (1);
	}
	return (0);
}

#define BUF_SIZE 30000

static int	print_file(char *filename, char *prog)
{
	int		fd;
	char	buf[BUF_SIZE];
	int		bytes_read;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
	{
		print_error(prog, filename);
		return (1);
	}
	bytes_read = read(fd, buf, BUF_SIZE);
	while (bytes_read > 0)
	{
		write(1, buf, bytes_read);
		bytes_read = read(fd, buf, BUF_SIZE);
	}
	if (bytes_read < 0)
	{
		print_error(prog, filename);
		close(fd);
		return (1);
	}
	close(fd);
	return (0);
}

int	cat(int argc, char **argv)
{
	int	i;
	int	res;

	res = 1;
	i = 1;
	while (i < argc)
	{
		res = res && print_file(argv[i], argv[0]);
		i++;
	}
	return (res);
}
