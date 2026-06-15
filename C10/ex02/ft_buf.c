/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 14:51:55 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 23:33:56 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_buf.h"

// malloc, free
#include <stdlib.h>
// read
#include <unistd.h>
// ft_string functions
#include "ft_string.h"

void	ft_bufpush(t_buf *buf, char *addition, int size)
{
	char	*new;
	int		i;
	int		old_buf_size;

	new = malloc(buf->size + size + 1);
	if (!new)
		return ;
	i = 0;
	while (i < buf->size)
	{
		new[i] = buf->buf[i];
		i++;
	}
	old_buf_size = buf->size;
	buf->size += size;
	while (i < buf->size)
	{
		new[i] = addition[i - old_buf_size];
		i++;
	}
	new[i] = 0;
	free(buf->buf);
	buf->buf = new;
}

static int	ft_find_prev_newline(t_buf *buf, int from)
{
	int	i;

	i = from;
	while (i >= 0)
	{
		if (buf->buf[i] == '\n')
			return (i);
		i--;
	}
	return (-1);
}

static void	ft_find_line(t_buf *buf, int *start, int *len)
{
	int	last_newline;
	int	prev_newline;

	if (buf->size == 0)
		return ;
	last_newline = ft_find_prev_newline(buf, buf->size - 1);
	if (last_newline == -1)
	{
		*start = 0;
		*len = buf->size;
		buf->size = 0;
	}
	else
	{
		prev_newline = ft_find_prev_newline(buf, last_newline - 1);
		*start = prev_newline + 1;
		*len = buf->size - *start;
		if (prev_newline < 0)
			buf->size = 0;
		else
			buf->size = prev_newline + 1;
	}
}

char	*ft_cpy_from_buf(t_buf *buf)
{
	int		start;
	int		len;
	char	*str;
	int		i;

	if (buf->size == 0)
		return (NULL);
	start = 0;
	len = 0;
	ft_find_line(buf, &start, &len);
	if (len == 0)
		return (NULL);
	str = malloc(len + 2);
	if (!str)
		return (NULL);
	i = 0;
	while (i < len)
	{
		str[i] = buf->buf[start + i];
		i++;
	}
	if (str[len - 1] != '\n')
		str[i++] = '\n';
	str[i] = '\0';
	return (str);
}

int	err_free(void *ptr)
{
	free(ptr);
	return (1);
}
