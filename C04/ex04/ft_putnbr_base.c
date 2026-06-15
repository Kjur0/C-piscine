/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:42:43 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 13:29:45 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	check_base(char *str)
{
	int				i;
	int				appeared[256];
	unsigned char	uc;

	i = 0;
	while (i < 256)
	{
		appeared[i] = 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		uc = (unsigned char)str[i];
		if (str[i] == '+' || str[i] == '-')
			return (1);
		if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			return (1);
		if (appeared[uc])
			return (1);
		appeared[uc] = 1;
		i++;
	}
	return (0);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(int nbr, char *base)
{
	const int	base_num = ft_strlen(base);

	if (base_num < 2)
		return ;
	if (check_base(base))
		return ;
	if (nbr < 0)
	{
		write(1, "-", 1);
		if (nbr < -base_num + 1)
			ft_putnbr_base(nbr / -base_num, base);
		write(1, &base[-(nbr % base_num)], 1);
	}
	if (nbr > base_num - 1)
		ft_putnbr_base(nbr / base_num, base);
	if (nbr >= 0)
		write(1, &base[nbr % base_num], 1);
}
