/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 15:50:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/13 00:03:48 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_print.h"

// write
#include <unistd.h>

static void	print_hex_byte(unsigned char c)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[c / 16], 1);
	write(1, &hex[c % 16], 1);
}

static void	print_offset(int offset)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 7;
	while (i >= 0)
	{
		write(1, &hex[(offset >> (i * 4)) & 0xf], 1);
		i--;
	}
}

static void	print_ascii(unsigned char *buf, int len)
{
	int	i;

	write(1, "|", 1);
	i = 0;
	while (i < len)
	{
		if (buf[i] >= 32 && buf[i] <= 126)
			write(1, &buf[i], 1);
		else
			write(1, ".", 1);
		i++;
	}
	write(1, "|", 1);
}

void	print_hex_line(unsigned char *buf, int len, int offset)
{
	int	i;

	print_offset(offset);
	write(1, "  ", 2);
	i = 0;
	while (i < 16)
	{
		if (i < len)
		{
			print_hex_byte(buf[i]);
			write(1, " ", 1);
		}
		else
			write(1, "   ", 3);
		if (i == 7)
			write(1, " ", 1);
		i++;
	}
	write(1, " ", 1);
	print_ascii(buf, len);
	write(1, "\n", 1);
}

static void	print_hex_word(unsigned char b1, unsigned char b2)
{
	char	*hex;

	hex = "0123456789abcdef";
	write(1, &hex[b2 / 16], 1);
	write(1, &hex[b2 % 16], 1);
	write(1, &hex[b1 / 16], 1);
	write(1, &hex[b1 % 16], 1);
}

static void	print_offset_short(int offset)
{
	int		i;
	char	*hex;

	hex = "0123456789abcdef";
	i = 6;
	while (i >= 0)
	{
		write(1, &hex[(offset >> (i * 4)) & 0xf], 1);
		i--;
	}
}

void	print_hex_line_default(unsigned char *buf, int len, int offset)
{
	int	i;
	int	j;

	print_offset_short(offset);
	write(1, " ", 1);
	i = 0;
	while (i < 8)
	{
		if (i * 2 + 1 < len)
		{
			print_hex_word(buf[i * 2], buf[i * 2 + 1]);
		}
		else if (i * 2 < len)
		{
			print_hex_word(buf[i * 2], 0);
		}
		else
		{
			j = 0;
			while (j < 4)
			{
				write(1, " ", 1);
				j++;
			}
		}
		write(1, " ", 1);
		i++;
	}
	write(1, "\n", 1);
}
