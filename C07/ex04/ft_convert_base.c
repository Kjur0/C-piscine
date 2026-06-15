/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:36:17 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/09 15:12:06 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_convert_base_helper(char *result, long nb, int neg, char *base_to);

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	check_base(char *str)
{
	int	i;
	int	appeared[256];

	if (ft_strlen(str) < 2)
		return (1);
	i = 0;
	while (i < 256)
	{
		appeared[i] = 0;
		i++;
	}
	i = 0;
	while (str[i])
	{
		if (str[i] == '+' || str[i] == '-')
			return (1);
		if (appeared[(int)str[i]])
			return (1);
		appeared[(int)str[i]] = 1;
		i++;
	}
	return (0);
}

int	index_of(char *base, char c)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_atoi_base(char *str, char *base)
{
	const int	base_num = ft_strlen(base);
	int			out;
	int			neg;
	int			i;

	out = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] != '\0')
	{
		if (index_of(base, str[i]) == -1)
			break ;
		out *= base_num;
		out += index_of(base, str[i]);
		i++;
	}
	return (neg * out);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	const int	to_len = ft_strlen(base_to);
	long		nb;
	int			len;
	int			neg;
	char		*result;

	if (check_base(base_from) || check_base(base_to))
		return (NULL);
	nb = ft_atoi_base(nbr, base_from);
	neg = 0;
	if (nb < 0)
	{
		neg = 1;
		nb = -nb;
	}
	len = 1;
	if (nb != 0)
		while (nb > 0 && len++)
			nb /= to_len;
	result = malloc(len + neg + 1);
	nb = ft_atoi_base(nbr, base_from);
	if (neg)
		nb = -nb;
	return (ft_convert_base_helper(result, nb, neg, base_to));
}
