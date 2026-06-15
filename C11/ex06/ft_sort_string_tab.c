/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_string_tab.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/12 12:28:42 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:30:30 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	ft_sort_string_tab(char **tab)
{
	int		i;
	char	*cur;
	int		j;

	i = 1;
	while (tab[i])
	{
		j = i - 1;
		cur = tab[i];
		while (j >= 0 && ft_strcmp(tab[j], cur) > 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = cur;
		i++;
	}
}
