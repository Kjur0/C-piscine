/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_advanced_sort_string_tab.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/11 16:16:31 by kjurkows          #+#    #+#             */
/*   Updated: 2026/02/12 12:29:46 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// insertion sort
void	ft_advanced_sort_string_tab(char **tab, int (*cmp)(char *, char *))
{
	int		i;
	char	*cur;
	int		j;

	i = 1;
	while (tab[i])
	{
		j = i - 1;
		cur = tab[i];
		while (j >= 0 && cmp(tab[j], cur) > 0)
		{
			tab[j + 1] = tab[j];
			j--;
		}
		tab[j + 1] = cur;
		i++;
	}
}
