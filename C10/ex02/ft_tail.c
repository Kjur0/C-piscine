/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:04:04 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:36:58 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_tail.h"

#include "ft_string.h"
#include "ft_print.h"
#include "ft_err.h"
#include "ft_lines.h"
#include "ft_util.h"

// open, close
#include <fcntl.h>
// read
#include <unistd.h>
// malloc, free
#include <stdlib.h>

int	handle_file_c(char *filename, int count, char *prog)
{
	const int	fd = open(filename, O_RDONLY);
	char		*out;

	if (fd < 0)
		return (ft_err(prog, filename));
	out = malloc(count + 1);
	if (!out)
		return (1);
	out[0] = 0;
	out[count] = 0;
	if (!get_tail_c(out, fd, count))
	{
		ft_err(prog, filename);
		close(fd);
		return (err_free(out));
	}
	ft_log(out);
	free(out);
	close(fd);
	return (0);
}

// write last 10 lines
int	handle_file_l(char *filename, char *prog)
{
	const int		fd = open(filename, O_RDONLY);
	t_line_storage	line_store;

	if (fd < 0)
		return (ft_err(prog, filename));
	line_store = read_lines(fd);
	if (line_store.count == -1)
	{
		ft_err(prog, filename);
		close(fd);
		return (1);
	}
	print_lines(line_store);
	close(fd);
	return (0);
}

static int	handle_one_file(t_control control, char *prog, int i,
				int *printed_any)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(control.files_to_read[i], O_RDONLY);
	if (fd < 0)
		return (ft_err(prog, control.files_to_read[i]));
	close(fd);
	if (*printed_any)
		ft_log("\n");
	ft_print_header(control.files_to_read[i]);
	if (control.bytes_to_read > 0)
		ret = handle_file_c(control.files_to_read[i],
				control.bytes_to_read, prog);
	else
		ret = handle_file_l(control.files_to_read[i], prog);
	*printed_any = 1;
	return (ret);
}

int	handle_files(t_control control, char *prog)
{
	int	i;
	int	ret;
	int	printed_any;

	i = -1;
	ret = 0;
	printed_any = 0;
	while (++i < control.file_count)
		ret = ret | handle_one_file(control, prog, i, &printed_any);
	return (ret);
}

int	handle_stdin(int count)
{
	char			*out;
	t_line_storage	line_store;

	if (count > 0)
	{
		out = malloc(count + 1);
		if (!out)
			return (1);
		out[0] = 0;
		out[count] = 0;
		if (!get_tail_c(out, 0, count))
			return (err_free(out));
		ft_log(out);
		free(out);
	}
	else
	{
		line_store = read_lines(0);
		if (line_store.count == -1)
			return (1);
		print_lines(line_store);
	}
	return (0);
}
