/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:37:17 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 13:34:08 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

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
			return (0);
		if (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
			return (0);
		if (appeared[uc])
			return (0);
		appeared[uc] = 1;
		i++;
	}
	return (i);
}

int	in(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i])
	{
		if (base[i] == c)
			return (1);
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

	if (!check_base(base))
		return (0);
	out = 0;
	neg = 1;
	i = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	while (str[i] == '+' || str[i] == '-')
		if (str[i++] == '-')
			neg *= -1;
	while (str[i] != '\0')
	{
		if (!in(str[i], base))
			break ;
		out *= base_num;
		out += index_of(base, str[i]);
		i++;
	}
	return (neg * out);
}
