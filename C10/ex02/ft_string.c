/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_string.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/10 21:41:35 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 15:42:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

#include "ft_tail.h"

void	ft_strcpy(char *dest, char *src, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		dest[i] = src[i];
		i++;
	}
}

void	ft_strshft_left(char *out, int bytes_read, int count, char *buf)
{
	int	i;

	i = 0;
	while (i < count - bytes_read && out[i + bytes_read])
	{
		out[i] = out[i + bytes_read];
		i++;
	}
	ft_strcpy(out + count - bytes_read, buf, bytes_read);
}

int	is_number(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

int	ft_atoi(char *str, t_control *cntrl)
{
	int	out;
	int	i;

	cntrl->atoi_read = str;
	out = 0;
	i = 0;
	if (!is_number(str))
		return (-2);
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			break ;
		out *= 10;
		out += str[i] - '0';
		i++;
	}
	return (out);
}
