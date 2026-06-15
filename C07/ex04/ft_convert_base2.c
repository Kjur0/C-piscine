/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:49:23 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/09 15:12:16 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str);
int	ft_atoi_base(char *str, char *base);

void	ft_swap(char *a, char *b)
{
	char	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

char	*ft_strrev(char *str)
{
	const int	len = ft_strlen(str);
	int			i;

	i = 0;
	while (i < len / 2)
	{
		ft_swap(&str[i], &str[len - i - 1]);
		i++;
	}
	return (str);
}

char	*ft_convert_base_helper(char *result, long nb, int neg, char *base_to)
{
	const int	to_len = ft_strlen(base_to);
	int			i;

	i = 0;
	if (nb == 0)
		result[i++] = base_to[0];
	else
	{
		while (nb > 0)
		{
			result[i++] = base_to[nb % to_len];
			nb /= to_len;
		}
	}
	if (neg)
		result[i++] = '-';
	result[i] = 0;
	return (ft_strrev(result));
}
