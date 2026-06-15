/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/08 13:33:12 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/08 22:24:19 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include <stdlib.h>

int	ft_iswhitespace(const char c)
{
	return (c == ' ' || c == '\n' || c == '\t');
}

int	ft_strlen(const t_string str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

t_string	ft_strtrim(t_string str)
{
	int			i;
	int			start;
	int			end;
	t_string	out;

	i = 0;
	while (ft_iswhitespace(str[i]))
		i++;
	start = i;
	while (str[i + 1])
		i++;
	while (ft_iswhitespace(str[i]))
		i--;
	end = i;
	out = malloc(end - start + 3);
	i = 0;
	while (start <= end)
	{
		out[i] = str[start];
		i++;
		start++;
	}
	out[i] = '\0';
	free(str);
	return (out);
}

t_string	ft_strcpy(const t_string dest, const t_string src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = 0;
	return (dest);
}

int	ft_strcmp(const t_string s1, const t_string s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
