/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 14:03:41 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:19:47 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

t_string	parse_word(int fd, char *buff)
{
	int			i;
	t_string	out;
	t_string	tmp;

	out = malloc(1);
	out[0] = 0;
	i = 1;
	while (read(fd, buff, 1))
	{
		if (*buff == '\n')
			break ;
		tmp = malloc(i + 1);
		ft_strcpy(tmp, out);
		tmp[i - 1] = *buff;
		tmp[i] = 0;
		free(out);
		out = tmp;
		i++;
	}
	return (ft_strtrim(out));
}

t_string	parse_number(int fd, char *buff)
{
	int			i;
	t_string	out;
	t_string	tmp;

	out = malloc(1);
	out[0] = 0;
	i = 1;
	while (read(fd, buff, 1) > 0)
	{
		if (*buff > '9' || *buff < '0')
			break ;
		tmp = malloc(i + 1);
		ft_strcpy(tmp, out);
		tmp[i - 1] = *buff;
		tmp[i] = 0;
		free(out);
		out = tmp;
		i++;
	}
	return (out);
}

int	parse_line(int fd, t_dict *dict)
{
	char			buff[1];
	const t_string	number = parse_number(fd, buff);
	t_string		word;

	if (!ft_strlen(number))
	{
		free(number);
		return (0);
	}
	if (*buff == '\n')
	{
		free(number);
		return (1);
	}
	if (*buff != ':')
		while (read(fd, buff, 1))
			if (*buff == ':')
				break ;
	word = parse_word(fd, buff);
	return (dict_add(dict, number, word));
}

t_dict	*parser(t_string dict_path)
{
	int		fd;
	t_dict	*dict;

	fd = open(dict_path, 0);
	dict = dict_init(0);
	while (parse_line(fd, dict))
		;
	return (dict);
}
