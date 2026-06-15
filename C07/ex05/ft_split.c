/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/09 15:12:34 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/09 15:28:32 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static int	is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i])
		if (charset[i++] == c)
			return (1);
	return (0);
}

static int	count_words(char *str, char *charset)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset))
			i++;
		if (!str[i])
			break ;
		count++;
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	return (count);
}

static char	*word_dup(char *str, char *charset)
{
	char	*dup;
	int		i;
	int		len;

	len = 0;
	while (str[len] && !is_sep(str[len], charset))
		len++;
	dup = malloc(len + 1);
	i = 0;
	while (i < len)
	{
		dup[i] = str[i];
		i++;
	}
	dup[i] = 0;
	return (dup);
}

char	**ft_split(char *str, char *charset)
{
	char	**split;
	int		words;
	int		i;
	int		j;

	words = count_words(str, charset);
	split = malloc(sizeof(char *) * (words + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		while (is_sep(str[i], charset))
			i++;
		if (!str[i])
			break ;
		split[j++] = word_dup(&str[i], charset);
		while (str[i] && !is_sep(str[i], charset))
			i++;
	}
	split[j] = NULL;
	return (split);
}
