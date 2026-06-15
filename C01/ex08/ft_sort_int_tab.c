/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kjurkows <kjurkows@student.42warsaw.pl>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 23:52:00 by kjurkows          #+#    #+#             */
/*   Updated: 2026/01/26 19:35:15 by kjurkows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	swap(int *a, int *b)
{
	int	tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

// selection sort
void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;
	int	j_min;

	i = 0;
	while (i < size - 1)
	{
		j_min = i;
		j = i + 1;
		while (j < size)
		{
			if (tab[j] < tab[j_min])
				j_min = j;
			j++;
		}
		if (j_min != i)
			swap(&tab[i], &tab[j_min]);
		i++;
	}
}
