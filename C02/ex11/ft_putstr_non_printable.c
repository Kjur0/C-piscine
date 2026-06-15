/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_non_printable.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 18:25:36 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/02 15:29:52 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar_non_printable(unsigned char c)
{
	const char	hex_chars[16] = "0123456789abcdef";

	if (c >= ' ' && c <= '~')
	{
		write(1, &c, 1);
		return ;
	}
	write(1, "\\", 1);
	write(1, &hex_chars[c / 16], 1);
	write(1, &hex_chars[c % 16], 1);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		ft_putchar_non_printable(str[i]);
		i++;
	}
}
