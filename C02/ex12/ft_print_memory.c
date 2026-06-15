/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:43:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/29 14:51:36 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_hex_addr(unsigned long addr)
{
	const char	hex_chars[16] = "0123456789abcdef";
	char		hex[16];
	int			i;

	i = 15;
	while (i >= 0)
	{
		hex[i] = hex_chars[addr % 16];
		addr /= 16;
		i--;
	}
	write(1, hex, 16);
	write(1, ": ", 2);
}

void	ft_putdata(unsigned char c, unsigned int i,
	unsigned int size)
{
	const char	hex_chars[16] = "0123456789abcdef";

	if (i < size)
	{
		write(1, &hex_chars[c / 16], 1);
		write(1, &hex_chars[c % 16], 1);
	}
	else
		write(1, "  ", 2);
}

void	ft_putchar_non_printable(unsigned char c)
{
	if (c >= ' ' && c <= '~')
	{
		write(1, &c, 1);
		return ;
	}
	write(1, ".", 1);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	unsigned char	*str;

	str = (unsigned char *)addr;
	i = 0;
	while (i < size)
	{
		ft_print_hex_addr((unsigned long)addr + i);
		j = 0;
		while (j < 16)
		{
			ft_putdata(str[i + j], i + j, size);
			if (j++ % 2)
				write(1, " ", 1);
		}
		j = 0;
		while (i + j < size && j < 16)
			ft_putchar_non_printable(str[i + j++]);
		write(1, "\n", 1);
		i += 16;
	}
	return (addr);
}

// int	main(void)
// {
// 	char	*a = "Bonjour les aminches\t\n\tc\a est fou\ttout\tce"
// 		" qu on peut faire avec\t\n\tprint_memory\n\n\n\tlol.lol\n ";
// 	ft_print_memory(a, 92);
// }
