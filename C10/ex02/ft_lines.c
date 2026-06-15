/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 12:56:58 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:28:39 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_lines.h"

#include "ft_tail.h"
#include "ft_string.h"
#include "ft_print.h"
#include "ft_buf.h"

// malloc, free
#include <stdlib.h>
// read
#include <unistd.h>

t_line_storage	read_lines(int fd)
{
	char			out[BUF_SIZE];
	t_buf			buf;
	int				bytes_read;
	t_line_storage	ls;
	int				i;

	buf.size = 0;
	buf.buf = malloc(1);
	bytes_read = read(fd, out, BUF_SIZE);
	while (bytes_read > 0)
	{
		ft_bufpush(&buf, out, bytes_read);
		bytes_read = read(fd, out, BUF_SIZE);
	}
	i = 0;
	while (i < 10)
		ls.lines[i++] = NULL;
	i = 9;
	while (buf.size > 0 && i >= 0)
		ls.lines[i--] = ft_cpy_from_buf(&buf);
	ls.count = 9 - i;
	free(buf.buf);
	if (bytes_read < 0)
		ls.count = -1;
	return (ls);
}

void	print_lines(t_line_storage line_stor)
{
	int	i;
	int	start;

	if (line_stor.count <= 0)
		return ;
	start = 10 - line_stor.count;
	i = start;
	while (i < 10)
	{
		if (line_stor.lines[i])
			ft_log(line_stor.lines[i]);
		i++;
	}
}
