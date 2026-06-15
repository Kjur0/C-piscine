/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 14:24:57 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/09 19:43:51 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	count_len(int size, char **strs, int sep_len)
{
	int		len;
	int		i;

	len = 0;
	i = 0;
	while (i < size)
	{
		len += ft_strlen(strs[i]);
		if (i++ < size - 1)
			len += sep_len;
	}
	return (len + 1);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	char	*joined;
	int		i;
	int		j;
	int		k;

	joined = malloc(count_len(size, strs, ft_strlen(sep)));
	i = 0;
	k = 0;
	while (k < size)
	{
		j = 0;
		while (strs[k][j])
			joined[i++] = strs[k][j++];
		if (k++ < size - 1)
		{
			j = 0;
			while (sep[j])
				joined[i++] = sep[j++];
		}
	}
	joined[i] = 0;
	return (joined);
}
