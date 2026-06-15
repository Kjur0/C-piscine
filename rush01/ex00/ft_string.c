/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/31 14:14:41 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/01 22:12:18 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>

static int	ft_wc(const char *str)
{
	int	i;
	int	count;
	int	new_word;

	i = 0;
	count = 0;
	new_word = 1;
	while (str[i])
	{
		if (str[i] == ' ')
			new_word = 1;
		else if (new_word)
		{
			count++;
			new_word = 0;
		}
		i++;
	}
	return (count);
}

static char	*ft_split(const char *str, const int len)
{
	char	*out;
	int		i;
	int		j;

	out = malloc(len);
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != ' ')
		{
			out[j] = str[i];
			j++;
		}
		i++;
	}
	return (out);
}

extern t_views	*ft_views_parser(const char *in)
{
	const int	len = ft_wc(in);
	char		*input;
	t_views		*out;
	int			i;

	if (len % 4)
		return (0);
	input = ft_split(in, len);
	out = malloc_views(len / 4);
	out->n = len / 4;
	i = 0;
	while (i < len)
	{
		out->views[i / out->n][i % out->n] = input[i] - '0';
		i++;
	}
	free(input);
	return (out);
}
